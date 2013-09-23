//<?php

namespace Zephir\EventManager;

class EventManager implements Zephir\EventManager\EventManagerInterface
{
    /**
     * @var array
     */
    protected events;

    protected eventClass = "Zend\EventManager\Event";

    protected identifiers;

    protected sharedManager = null;


    public function __construct(identifiers = null)
    {
        let this->events = [];
        let this->identifiers = [];

        this->setIdentifiers(identifiers);
    }

    public function setIdentifiers(identifiers)
    {
        if identifiers === null {
             return;
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

    public function addIdentifiers(identifiers)
    {
        if identifiers == null {
            return;
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

    public function getIdentifiers()
    {
        return this->identifiers;
    }

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
        let listener = new Zend\Stdlib\CallbackHandler(callback, ["event":  event, "priority":  priority]);

        queue->insert(listener, priority);
    }

    public function trigger(event, target = null, argv = null, callback = null)
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
                throw new Zephir\EventManager\Exception\InvalidCallbackException('Invalid callback provided');
            }
        }

        e->stopPropagation(false);
        return this->triggerListeners(event, e, callback);
    }

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
                throw new Zephir\EventManager\Exception\InvalidCallbackException('Invalid callback provided');
            }
        }

        e->stopPropagation(false);
        return this->triggerListeners(event, e, callback);
    }

    public function triggerListeners(event, <Zephir\EventManager\EventInterface> e, callback = null)
    {
        var responses, listeners, sharedListeners, sharedWildcardListeners, wildcardListeners;

        let responses = new Zephir\EventManager\ResponseCollection();
        let listeners = this->getListeners(event);

        let sharedListeners         = this->getSharedListeners(event);
        let wildcardListeners       = this->getListeners("*");
        let sharedWildcardListeners = this->getSharedListeners("*");

        let listeners = clone listeners;
        listeners->insertListeners(listeners, sharedListeners);
        listeners->insertListeners(listeners, wildcardListeners);
        listeners->insertListeners(listeners, sharedWildcardListeners);

        var listener, listenerCallback;
        for listener in listeners {

            let listenerCallback = listener->getCallback();

            responses->push(call_user_func(listenerCallback, e));

            if e->propagationIsStopped() {
                responses->setStopped(true);
                break;
            }

            if callback {
                 if call_user_func(callback, responses->last()) {
                     responses->setStopped(true);
                     break;
                 }
            }
        }

        return responses;
    }

    public function detach(listener)
    {
    }

    public function getEvents()
    {
    }

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

    public function getListeners(event)
    {
    }

    public function clearListeners(event)
    {
    }

    public function setEventClass(eventClass)
    {
    }

    public function attachAggregate(agregate, priority = 1)
    {
    }

    public function detachAggregate(aggregate)
    {
    }
}
