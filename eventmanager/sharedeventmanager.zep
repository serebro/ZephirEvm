//<?php

namespace Zephir\EventManager;

class SharedEventManager implements Zephir\EventManager\SharedEventAggregateAwareInterface, Zephir\EventManager\SharedEventManagerInterface
{
    protected identifiers;

    public function attach(id, event, callback, int priority = 1)
    {
        var ids, identifiers, listeners;

        let listeners   = [];
        let identifiers = this->identifiers;

        if identifiers === null {
            let identifiers = [];
        }

        if typeof(id) != "array" {
            let ids = [id];
        } else {
            let ids = id;
        }

        for id in ids {
            if !array_key_exists(id, identifiers) {
                let identifiers[id] = new Zephir\EventManager\EventManager(id);
            }

            var evm;
            let evm = identifiers[id];

            let listeners[] = evm->attach(event, callback, priority);
        }

        let this->identifiers = identifiers;

        if count(listeners) > 1 {
            return listeners;
        }

        return listeners[0];
    }

    public function attachAggregate(<Zephir\EventManager\SharedListenerAggregateInterface> aggregate, priority)
    {
        return aggregate->attachShared(this, priority);
    }

    public function detach(id, <Zend\Stdlib\CallbackHandler> listener)
    {
        var identifiers;
        let identifiers = this->identifiers;

        if !array_key_exists(id, identifiers) {
            return false;
        }

        var evm;
        let evm = identifiers[id];
        return evm->detach(listener);
    }

    public function detatchAggregate(<Zephir\EventManager\SharedListenerAggregateInterface> aggregate)
    {
        return aggregate->detachShared(this);
    }

    public function getEvents(id)
    {
        var evm, identifiers;
        let identifiers = this->identifiers;

        if !array_key_exists(id, identifiers) {
            if id != "*" {
                if array_key_exists("*", identifiers) {
                    let evm = identifiers["*"];
                    return evm->getEvents();
                }
            }

            return false;
        }

        let evm = identifiers[id];
        return evm->getEvents();
    }

    public function getListeners(id, event)
    {
        if !array_key_exists(id, this->identifiers) {
            return false;
        }

        var evm, identifiers;
        let identifiers = this->identifiers;
        let evm = identifiers[id];

        return evm->getListeners(event);
    }

    public function clearListeners(id, event = null)
    {
        if !array_key_exists(id, this->identifiers) {
            return false;
        }

        var identifiers;
        let identifiers = this->identifiers;

        if event === null {
            unset identifiers[id];
            let this->identifiers = identifiers;

            return true;
        }

        var evm;
        let evm = identifiers[id];
        return evm->clearListeners(event);
    }
}

