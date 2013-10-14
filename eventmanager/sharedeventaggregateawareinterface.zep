//<?php

namespace Zephir\EventManager;

interface SharedEventAggregateAwareInterface
{
    public function attachAggregate(<Zephir\EventManager\SharedListenerAggregateInterface> aggregate, int priority = 1);
    public function detachAggregate(<Zephir\Eventmanager\SharedListenerAggregateInterface> aggregate);
}
