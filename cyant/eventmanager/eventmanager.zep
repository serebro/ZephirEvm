/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Cyant\EventManager;

/**
 * Event manager: notification system
 *
 * Use the EventManager when you want to create a per-instance notification
 * system for your objects.
 */
class EventManager implements Cyant\EventManager\EventManagerInterface
{
    /**
     * Subscribed events and their listeners
     *
     * @var array
     */
    protected events;

    /**
     * Identifiers, used to pull shared signals from SharedEventManagerInterface instance
     *
     * @var array
     */
    protected identifiers;

    /**
     * Shared event manager
     *
     * @var null|SharedEventManagerInterface
     */
    protected sharedManager = null;

    /**
     * @var boolean
     */
    protected orderedByPriority = true;

    /**
     * Constructor
     *
     * Allows optionally specifying identifier(s) to use to pull signals from a
     * SharedEventManagerInterface.
     *
     * @param  null|string|int|array|Traversable identifiers
     */
    public function __construct(identifiers = null)
    {
        let this->events      = [];
        let this->identifiers = [];

        this->setIdentifiers(identifiers);
    }

    /**
     * Set shared event manager
     *
     * @param  SharedEventManagerInterface sharedEventManager
     * @return void
     */
    public function setSharedManager(<Cyant\EventManager\SharedEventManagerInterface> sharedEventManager)
    {
        let this->sharedManager = sharedEventManager;
    }

    /**
     * Get shared event manager
     *
     * @return SharedEventManagerInterface|null
     */
    public function getSharedManager() -> <Cyant\EventManager\SharedManagerInterface>
    {
        return this->sharedManager;
    }

    /**
     * Attach a listener to an event
     *
     * The first argument is the event, and the next argument describes a
     * callback that will respond to that event.
     *
     * The last argument indicates a priority at which the event should be
     * executed. By default, this value is 1; however, you may set it for any
     * integer value. Higher values have higher priority (i.e., execute first).
     *
     * You can specify "*" for the event name. In such cases, the listener will
     * be triggered for every event.
     *
     * @param  string   event An event or array of event names
     * @param  listener
     * @param  int      priority If provided, the priority at which to register the callable
     * @return if attaching (to allow later unsubscribe)
     * @throws Exception\InvalidArgumentException
     */
    public function attach(string event, listener, int priority = 1)
    {
        if !isset this->events[event] {
            let this->events[event] = [];
        }

        if !isset this->events[event][priority . ".0"] {
            let this->events[event][priority . ".0"] = [];
        }

        array_push(this->events[event][priority . ".0"], listener);
        let this->orderedByPriority = false;

        return listener;
    }

    /**
     * Attach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call attach()
     * one or more times, typically to attach to multiple events using local
     * methods.
     *
     * @param  ListenerAggregateInterface aggregate
     * @param  int                        priority If provided, a suggested priority for the aggregate to use
     * @return mixed return value of {@link ListenerAggregateInterface::attach()}
     */
    public function attachAggregate(<Cyant\EventManager\ListenerAggregateInterface> aggregate, priority = 1)
    {
        return aggregate->attach(this, priority);
    }

    /**
     * Unsubscribe a listener from an event
     *
     * This method is quite inefficient as it needs to traverse each queue, so use with care! If you are that
     * worried about performance, you should always filter by the event name so that less work is done
     *
     * @param  listener
     * @param  string   eventName
     * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
     */
    public function detach(listener, string eventName = null)
    {
        var index, listeners, key;

        if (!empty(eventName) && isset(this->events[eventName])) {

            for index, listeners in this->events[eventName] {

                let key = array_search(listener, listeners, true);
                if (key !== false) {
                    unset(this->events[eventNameindex][index][key]);
                    return true;
                }
            }

            return false;
        }

        var event;
        for event in this->events {
            for listener in event {
                let key = array_search(listener, listeners, true);
                if (key !== false) {
                    unset(this->events[eventNameindex][index][key]);
                    return true;
                }
            }
        }

        return false;
    }

    /**
     * Detach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call detach()
     * of all previously attached listeners.
     *
     * @param  ListenerAggregateInterface aggregate
     * @return bool
     */
    public function detachAggregate(<Cyant\Eventmanager\ListenerAggregateInterface> aggregate)
    {
        return aggregate->detach(this);
    }

    /**
     * Trigger all listeners for a given event (optionally until a callback evaluates to true)
     *
     * @param  string              eventName
     * @param  EventInterface|null event
     * @param  callable|null       callback
     * @return ResponseCollection All listener return values
     */
    public function trigger(string eventName, <Cyant\EventManager\EventInterface> event = null, var callback = null) -> <Cyant\EventManager\ResponseCollection>
    {
        // Initial value of stop propagation flag should be false
        if (event == null) {
            let event = new Cyant\EventManager\Event();
        }

        event->stopPropagation(false);

        var responses, listeners;

        let responses = [];
        let listeners = this->getListeners(eventName);


        var lastResponse, listenersByPriority, listener;
        for listenersByPriority in listeners {
            for listener in listenersByPriority {

                let lastResponse = call_user_func(listener, event);
                let responses[]  = lastResponse;

                if (event->isPropagationStopped() || (callback && {callback}(lastResponse)) ) {

                    var responseCollection;
                    let responseCollection = new Cyant\EventManager\ResponseCollection(responses);
                    responseCollection->setStopped(true);

                    return responseCollection;
                }
            }
        }

        return new Cyant\EventManager\ResponseCollection(responses);
    }

    /**
     * {@inheritDoc}
     */
    public function getEventNames()
    {
        return array_keys(this->events);
    }

    /**
     * {@inheritDoc}
     */
    public function getListeners(eventName)
    {
        var listeners, wildcardListeners, sharedListeners;
        let listeners = [], wildcardListeners = [], sharedListeners = [];

        // pre-order all listeners by priority
        if (!this->orderedByPriority) {

            var name, listenersByPriority;
            for name, listenersByPriority in this->events {
                krsort(this->events[name], SORT_NUMERIC);
            }
        
            let this->orderedByPriority = true;
        }

        int mergeCount = 0;

        // retrieve listeners
        if isset this->events[eventName] {

            let listeners = this->events[eventName];
            if (listeners) {
                let mergeCount++;
            }
        }
        
        if isset this->events["*"] {

            let wildcardListeners = this->events["*"];
            if (wildcardListeners) {
                let mergeCount++;
            }
        }


        if this->sharedManager !== null {

            let sharedListeners = this->sharedManager->getListeners(this->identifiers, eventName);
            if sharedListeners {
                let mergeCount++;
            }
        }
        
        // merge
        if (mergeCount > 1) {
            let listeners = array_merge_recursive(listeners, wildcardListeners, sharedListeners);
            krsort(listeners, SORT_NUMERIC);
        } else {
            if wildcardListeners {
                let listeners = wildcardListeners;
            } else {
                 if sharedListeners {
                    let listeners = sharedListeners;
                 }
            }
        }
        
        return listeners; 
    }

    /**
     * {@inheritDoc}
     */
    public function clearListeners(eventName)
    {
        unset(this->events[eventName]);
    }

    /**
     * {@inheritDoc}
     */
    public function setIdentifiers(identifiers)
    {
        if (identifiers instanceof Traversable) {
            let identifiers = iterator_to_array(identifiers);
        }

        let this->identifiers = identifiers;
    }

    /**
     * {@inheritDoc}
     */
    public function addIdentifiers(identifiers)
    {
        if (identifiers instanceof Traversable) {
            let identifiers = iterator_to_array(identifiers);
        }

        let this->identifiers = array_unique(array_merge(this->identifiers, identifiers));
    }

    /**
     * {@inheritDoc}
     */
    public function getIdentifiers()
    {
        return this->identifiers;
    }

    /**
     * Prepare arguments
     *
     * Use this method if you want to be able to modify arguments from within a
     * listener. It returns an ArrayObject of the arguments, which may then be
     * passed to trigger() or triggerUntil().
     *
     * @param  array args
     * @return ArrayObject
     */
    public function prepareArgs(args)
    {
        return new ArrayObject(args);
    }
}
