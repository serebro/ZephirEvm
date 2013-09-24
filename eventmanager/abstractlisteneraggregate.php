//<?php

namespace Zephir\Eventmanager;

abstract class AbstractListenerAggregate implements ListenerAggregateInterface
{
    protected listeners;

    public function detach(<Zephir\EventManager\EventManagerInterface> events)
    {
        var index, callback, listeners;
        let listeners = this->listeners;

        for index, callback in listeners {

            if events->detach(callback) {
                unset listeners[index];
            }
        }

        let this->listeners = listeners;
    }
}
