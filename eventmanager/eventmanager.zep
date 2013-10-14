//<?php

namespace Zephir\EventManager;

class EventManager implements Zephir\EventManager\EventManagerInterface
{
    /**
     * Subscribed events and their listeners
     *
     * @var PriorityQueue[]
     */
    protected events;

    /**
     * Class representing the event being emitted
     *
     * @var string
     */
    protected eventClass = "Zend\EventManager\Event";

    /**
     * Identifiers, used to pull shared signals from an SharedEventManagerInterface instance
     *
     * @var array
     */
    protected identifiers;

    /**
     * Shared event manager
     *
     * @var false|null|SharedEventManagerInterface
     */
    protected sharedManager = null;

    /**
     * Constructor
     *
     * Allows optionally specifying identifier(s) to use to pull signals from a shared
     * EventManagerInterface.
     *
     * return null|string|int|array|\Traversable
     */
    public function __construct(identifiers = null)
    {
        let this->events = [];
        let this->identifiers = [];ac

        this->setIdentifiers(identifiers);
    }

    /**
     * Set the event class to utilize
     *
     * @param string eventClass
     * @return EventManager
     */
    public function setEventClass(string eventClass) -> <Zephir\EventManager\EventManagerInterface>
    {
        let this->eventClass = eventClass;
        return this;
    }

    /**
     * Set shared event manager
     *
     * @param SharedEventManagerInterface sharedEventManager
     * @return EventManager
     */
    public function setSharedManager(<Zephir\EventManager\SharedEventManagerInterface> sharedEventManager) -> <Zephir\EventManager\EventManagerInterface>
    {
        let this->sharedManager = sharedEventManager;
        Zephir\EventManager\StaticEventManager::setInstance(sharedEventManager);
        return this;
    }

    /**
     * Remove any shared event manager currently attached
     *
     * @return void
     */
    public function unsetSharedManager() -> void
    {
        let this->sharedManager = false;
    }

    /**
     * Get shared event manager
     *
     * If one is not defined, but we have a static instance in
     * StaticEventManager, that one will be used and set in this instance.
     *
     * If none is available in the StaticEventManager, a boolean false is
     * returned.
     *
     * @return false|SharedEventManagerInterface
     */
    public function getSharedManager() -> <Zephir\EventManager\SharedEventManagerInterface> | boolean
    {
        if this->sharedManager === false {
            return false;
        }

        if this->sharedManager instanceof Zephir\EventManager\SharedEventManagerInterface {
            return this->sharedManager;
        }

        if !Zephir\EventManager\StaticEventManager::hasInstance() {
            return false;
        }

        let this->sharedManager = Zephir\EventManager\StaticEventManager::getInstance();
        return this->sharedManager;
    }

    /**
     * Get the identifier(s) for this EventManager
     *
     * @return array
     */
    public function getIdentifiers()
    {
        return this->identifiers;
    }

    /**
     * Set the identifiers (overrides any currently set identifiers)
     *
     * @param string|int|array|\Traversable identifiers
     *
     * @return EventManager
     */
    public function setIdentifiers(identifiers) -> <Zephir\EventManager\EventManager>
    {
        if identifiers === null {
             return this;
        }

        if identifiers instanceof Traversable {
            let identifiers = iterator_to_array(identifiers);
        }

        if is_array(identifiers) {
            let this->identifiers = array_unique(identifiers);
        } else {
            let this->identifiers = [identifiers];
        }

        return this;
    }

    /**
     * Add some identifier(s) (appends to any currently set identifiers)
     *
     * @param string|int|array|\Traversable
     *
     * @return EventManager
     */
    public function addIdentifiers(identifiers) -> <Zephir\EventManager\Eventmanager>
    {
        if identifiers == null {
            return this;
        }

        if identifiers instanceof Traversable {
            let identifiers = iterator_to_array(identifiers);
        }

        if is_array(identifiers) {
            let this->identifiers = array_unique(array_merge(this->identifiers, identifiers));
        } else {
            let this->identifiers = array_unique(array_merge(this->identifiers, [identifiers]));
        }

        return this;
    }


    /**
     * Trigger all listeners for a given event
     *
     * Can emulate triggerUntil() if the last argument provided is a callback.
     *
     * @param  string $event
     * @param  string|object $target Object calling emit, or symbol describing target (such as static method name)
     * @param  array|ArrayAccess $argv Array of arguments; typically, should be associative
     * @param  null|callable $callback
     * @return ResponseCollection All listener return values
     * @throws Exception\InvalidCallbackException
     */
    public function trigger(event, target = null, argv = null, callback = null) -> <Zend\EventManager\ResponseCollection>
    {
        if argv === null {
            let argv = [];
        }

        var e;

        if event instanceof Zephir\EventManger\EventInterface {
            let e        = event;
            let event    = e->getName();
            let callback = target;
        } else {
            if (target instanceof Zephir\EventManager\EventInterface) {
                let e = target;
                e->setName(event);
                let callback = argv;
            } else {
                if argv instanceof Zephir\EventManager\EventInterface {
                    let e = argv;
                    e->setName(event);
                    e->setTarget(target);
                } else {
                    let e        = event;
                                let event    = e->getName();
                                let callback = target;
                }
            }
        }

        if callback !== null {
            if !is_callable(callback) {
            }
        }

        e->stopPropagation(false);
        return this->triggerListeners(event, e, callback);
    }

    /**
     * Trigger listeners until return value of one causes a callback to
     * evaluate to true
     *
     * Triggers listeners until the provided callback evaluates the return
     * value of one as true, or until all listeners have been executed.
     *
     * @param  string $event
     * @param  string|object $target Object calling emit, or symbol describing target (such as static method name)
     * @param  array|ArrayAccess $argv Array of arguments; typically, should be associative
     * @param  callable $callback
     * @return ResponseCollection
     * @throws Exception\InvalidCallbackException if invalid callable provided
     */
    public function triggerUntil(event, target, argv = null, callback = null)
    {
        if argv === null {
            let argv = [];
        }

        var e;

        if event instanceof Zephir\EventManger\EventInterface {
            let e        = event;
            let event    = e->getName();
            let callback = target;
        } else {
            if (target instanceof Zephir\EventManager\EventInterface) {
                let e = target;
                e->setName(event);
                let callback = argv;
            } else {
                if argv instanceof Zephir\EventManager\EventInterface {
                    let e = argv;
                    e->setName(event);
                    e->setTarget(target);
                } else {
                    var className;
                    let className = this->eventClass;

                    let e = new className;
                    e->setName(event);
                    e->setTarget(target);
                    e->setParams(argv);
                }
            }
        }

        if callback !== null {
            if !is_callable(callback) {

            }
        }

        e->stopPropagation(false);
        return this->triggerListeners(event, e, callback);
    }

    /**
     * Attach a listener to an event
     *
     * The first argument is the event, and the next argument describes a
     * callback that will respond to that event. A CallbackHandler instance
     * describing the event listener combination will be returned.
     *
     * The last argument indicates a priority at which the event should be
     * executed. By default, this value is 1; however, you may set it for any
     * integer value. Higher values have higher priority (i.e., execute first).
     *
     * You can specify "*" for the event name. In such cases, the listener will
     * be triggered for every event.
     *
     * @param  string|array|ListenerAggregateInterface $event An event or array of event names. If a ListenerAggregateInterface, proxies to {@link attachAggregate()}.
     * @param  callable|int $callback If string $event provided, expects PHP callback; for a ListenerAggregateInterface $event, this will be the priority
     * @param  int $priority If provided, the priority at which to register the callable
     * @return CallbackHandler|mixed CallbackHandler if attaching callable (to allow later unsubscribe); mixed if attaching aggregate
     * @throws Exception\InvalidArgumentException
     */
    public function attach(event, callback = null, priority = 1)
    {
        if event instanceof ListenerAggregateInterface {
             throw new Exception("Not yet implemented");
        }

        if !is_callable(callback) {
            throw new Exception("invalid callback");
        }

        if is_array(event) {

            var e, listeners;
            let listeners = [];

            for e in event {
                let listeners[] = this->attach(e, callback, priority);
            }

            return listeners;
        }

        if !array_key_exists(event, this->events) {
            let this->events[event] = new SplPriorityQueue();
        }

        var events, queue, listener;

        let events = this->events;
        let queue = events[event];

        queue->insert(callback, priority);
    }

    /**
     * Attach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call attach()
     * one or more times, typically to attach to multiple events using local
     * methods.
     *
     * @param  ListenerAggregateInterface $aggregate
     * @param  int $priority If provided, a suggested priority for the aggregate to use
     * @return mixed return value of {@link ListenerAggregateInterface::attach()}
     */
    public function attachAggregate(<Zephir\EventManager\ListenerAggregateInterface> aggregate, priority = 1)
    {
        return aggregate->attach(this, priority);
    }

    /**
     * Unsubscribe a listener from an event
     *
     * @param  CallbackHandler|ListenerAggregateInterface $listener
     * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
     * @throws Exception\InvalidArgumentException if invalid listener provided
     */
    public function detach(listener)
    {
        if listener instanceof Zephir\EventManager\ListenegerAggregateInterface {
            return this->detachAggregate(listener);
        }

        if listener instanceof Zend\Stdlib\CallbackHandler {
            // todo: remove when zephirs supports not operator with instanceof
        } else {

            var received;
            if is_object(listener) {
                let received = get_class(listener);
            } else {
                let received = gettype(listener);
            }

            throw new Zephir\Eventmanager\Exception\InvalidArgumentException(sprintf(
                "%s: expected a ListenerAggregateInterface or CallbackHandler; received \"%s\"",
                "Zephir\EventManger\EventManager::detatch", listener
            ));
        }

        var event;
        let event = listener->getMetadatum("event");

        if !event {
            return false;
        }

        if empty(event) {
            return false;
        }

        var ret;
        let ret = this->getListeners(event);

        if !ret->remove(listener) {
            return false;
        }

        var events;
        let events = this->events;

        if !count(events[event]) {
            unset events[event];
            let this->events = events;
        }

        return true;
    }

    /**
     * Detach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call detach()
     * of all previously attached listeners.
     *
     * @param  ListenerAggregateInterface $aggregate
     * @return mixed return value of {@link ListenerAggregateInterface::detach()}
     */
    public function detachAggregate(<Zephir\EventManager\ListenerAggregateInterface> aggregate)
    {
        return aggregate->detach(this);
    }

    /**
     * Retrieve all registered events
     *
     * @return array
     */
    public function getEvents()
    {
        return array_keys(this->events);
    }

    /**
     * Retrieve all listeners for a given event
     *
     * @param  string $event
     * @return PriorityQueue
     */
    public function getListeners(string event)
    {
        if !array_key_exists(event, this->events) {
            return new SplPriorityQueue();
        }

        var events;
        let events = this->events;
        return events[event];
    }

    /**
     * Clear all listeners for a given event
     *
     * @param  string $event
     * @return void
     */
    public function clearListeners(string event)
    {
        var events;
        let events = this->events;

        if !empty(events[event]) {
            unset events[event];
        }
    }

    /**
     * Prepare arguments
     *
     * Use this method if you want to be able to modify arguments from within a
     * listener. It returns an ArrayObject of the arguments, which may then be
     * passed to trigger() or triggerUntil().
     *
     * @param  array $args
     * @return ArrayObject
     */
    public function prepareArgs(args)
    {
        if typeof args != "array" {
             trigger_error("First argument passed to prepareArgs must be of type array", E_USER_ERROR);
        }

        return new ArrayObject(args);
    }

    /**
     * Trigger listeners
     *
     * Actual functionality for triggering listeners, to which both trigger() and triggerUntil()
     * delegate.
     *
     * @param  string           $event Event name
     * @param  EventInterface $e
     * @param  null|callable    $callback
     * @return ResponseCollection
     */
    public function triggerListeners(event, <Zephir\EventManager\EventInterface> e, callback = null) -> <SplStack>
    {
        var responses, listeners, sharedListeners, sharedWildcardListeners, wildcardListeners;

        let responses = new SplStack();
        let listeners = this->getListeners(event);

        let sharedListeners         = this->getSharedListeners(event);
        let wildcardListeners       = this->getListeners("*");
        let sharedWildcardListeners = this->getSharedListeners("*");

        this->insertListeners(listeners, sharedListeners);
        this->insertListeners(listeners, wildcardListeners);
        this->insertListeners(listeners, sharedWildcardListeners);

        var listener, listenerCallback;
        for listener in iterator_to_array(listeners) {

            let listenerCallback = listener;

            responses->push(call_user_func(listenerCallback, e));

            if e->propagationIsStopped() {
                //responses->setStopped(true);
                break;
            }

            if callback {
                 if call_user_func(callback, responses->top()) {
                     //responses->setStopped(true);
                     break;
                 }
            }
        }

        return responses;
    }


    /**
     * Get list of all listeners attached to the shared event manager for
     * identifiers registered by this instance
     *
     * @param  string $event
     * @return array
     */
    public function getSharedListeners(event)
    {
        if this->sharedManager === null {
            return [];
        }

        var identifiers, sharedManager, sharedListeners;

        let identifiers     = this->getIdentifiers();
        let sharedManager   = this->sharedManager;
        let sharedListeners = [];

        if !in_array("*", identifiers) {
            let identifiers[] = "*";
        }

        var_dump(identifiers);

        var id;
        for id in identifiers {

            var listeners;
            let listeners = sharedManager->getListeners(id, event);

            if !listeners {
                continue;
            }

            if !is_array(listeners) {
                if listeners instanceof Traversable {
                    // todo: remove this when zephir has support for the not operator on when using instanceof
                } else {
                    continue;
                }
            }

            var listener;
            for listener in listeners {
                if listener instanceof Callback {
                    // todo: remove this when zephir has support for the not operator on when using instanceof
                } else {
                    continue;
                }

                let sharedListeners[] = listener;
            }
        }

        return sharedListeners;
    }

    /**
     * Add listeners to the master queue of listeners
     *
     * Used to injected shared listeners and wildcard listeners.
     *
     * @param PriorityQueue masterListeners
     * @param PriorityQueue listeners
     *
     * @return void
     */
    protected function insertListeners(<Zend\Stdlib\PriorityQueue> masterListeners, <Zend\Stdlib\PriorityQueue> listeners)
    {
        if listeners instanceof SplPriorityQueue {
            let listeners = iterator_to_array(listeners);
        }

        var listener;
        for listener in listeners {
/*
            var priority;
            let priority = listener->getMetadatum("priority");

            if priority === null {
                let priority = 1;
            }

            if is_array(priority) {
                let priority = array_shift(priority);
            }
*/
            masterListeners->insert(listener, 1);
        }
    }
}
