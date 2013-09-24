//<?php

namespace Zephir\EventManager;

interface SharedListenerAggregateInterface
{
    public function attachShared(<Zephir\EventManager\SharedEventManagerInterface> events);
    public function detatchShared(<Zephir\EventManager\SharedEventManagerInterface> events);
}

