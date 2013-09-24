//<?php

namespace Zephir\EventManager;

/**
 * todo: replace all occurrences of self with static
 */
class StaticEventManager extends Zephir\EventManager\SharedEventManager
{
    /**
     * @var StaticEventManager
     */
    protected static instance = null;

    /**
     * Singleton
     */
    protected function __construct()
    {
    }

    /**
     * Singleton
     *
     * @return void
     */
    private function __clone()
    {
    }

    /**
     * Retrieve instance
     *
     * @return StaticEventManager
     */
    public static function getInstance()
    {
        var instance;
        let instance = self::instance;

        if typeof instance == "null" {
            self::setInstance(new self());
        }

        return self::instance;
    }

    public static function setInstance(<Zephir\EventManager\SharedEventManagerInterface> instance)
    {
        let self::instance = instance;
    }

    public static function hasInstance()
    {
        return self::instance !== null;
    }

    public static function resetInstance()
    {
        let self::instance = null;
    }
 }
