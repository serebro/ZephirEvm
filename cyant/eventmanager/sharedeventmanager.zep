/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Cyant\EventManager;

/**
 * Shared/contextual EventManager
 *
 * Allows attaching to EMs composed by other classes without having an instance first.
 * The assumption is that the SharedEventManager will be injected into EventManager
 * instances, and then queried for additional listeners when triggering an event.
 */
class SharedEventManager implements Cyant\EventManager\SharedEventManagerInterface
{
    /**
     * Identifiers that are mapped to listeners
     *
     * @var array
     */
    protected identifiers;

    /**
     * Stupid zephir does not support default values with array....
     */
    public function __construct()
    {
        let this->identifiers = [];
    }

    /**
     * Attach a listener to an event
     *
     * Allows attaching a callback to an event offered by one or more
     * identifying components
     *
     * @param  string|array identifiers Identifier(s) for event emitting component(s)
     * @param  string       eventName
     * @param  callable     listener PHP Callback
     * @param  int          priority Priority at which listener should execute
     * @return callable
     */
    public function attach(identifiers, string eventName, var listener, int priority = 1)
    {
        var identifier;

        if is_string(identifiers) {
            let identifiers = [identifiers];
        }

        for identifier in identifiers {

            if null {

            }
            /*
            if !isset this->identifiers[identifier] {
                let this->identifiers[identifer] = [];
            }

            if !isset this->identifiers[identifier][eventName] {
                let this->identifiers[identifier][eventName] = [];
            }

            if !isset this->identifiers[identifier][eventName][priority . ".0"] {
                let this->identifiers[identifier][eventName][priority . ".0"] = [];
            }

            array_push(this->identifiers[identifier][eventName][priority . ".0"], listener);
            */
        }

        return listener;
    }

    /**
     * Attach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call attachShared()
     * one or more times, typically to attach to multiple events using local
     * methods.
     *
     * @param  SharedListenerAggregateInterface aggregate
     * @param  int priority If provided, a suggested priority for the aggregate to use
     * @return mixed return value of {@link SharedListenerAggregateInterface::attachShared()}
     */
    public function attachAggregate(<Cyant\EventManager\SharedListenerAggregateInterface> aggregate, int priority = 1)
    {
        return aggregate->attachShared(this, priority);
    }

    /**
     * Detach a listener from an event offered by a given resource
     *
     * @param  string|int identifier
     * @param  callable   listener
     * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
     */
    public function detach(identifier, var listener)
    {
        if isset this->identifiers[identifier] {
        /*
            foreach (this->identifiers[identifier] as &event) {
                foreach (event as &listeners) {
                    if ((key = array_search(listener, listeners, true)) !== false) {
                        unset(listeners[key]);
                        return true;
                    }
                }
            }
            */
        }

        return false;
    }

    /**
     * Detach a listener aggregate
     *
     * Listener aggregates accept an SharedEventManagerInterface instance, and call detachShared()
     * of all previously attached listeners.
     *
     * @param  SharedListenerAggregateInterface aggregate
     * @return mixed return value of {@link SharedListenerAggregateInterface::detachShared()}
     */
    public function detachAggregate(<Cyant\EventManager\SharedListenerAggregateInterface> aggregate)
    {
        return aggregate->detachShared(this);
    }

    /**
     * Retrieve all listeners for a given identifier and event
     *
     * @param  string|string[] identifiers
     * @param  string|int      eventName
     * @return array
     */
    public function getListeners(identifiers, eventName)
    {
        /*
        var listeners, identifier;
        let listeners = [];


        for identifer in identifiers {
            if (isset(this->identifiers[identifier][eventName])) {
                let listeners = array_merge(listeners, this->identifiers[identifier][eventName]);
            }

            if (isset(this->identifiers[identifier]["*"])) {
                let listeners = array_merge(listeners, this->identifiers[identifier]["*"]);
            }
        }

        if (isset(this->identifiers["*"]) && !in_array("*", identifiers, true)) {
            if (isset(this->identifiers["*"][eventName])) {
                let listeners = array_merge(listeners, this->identifiers["*"][eventName]);
            }

            if (isset(this->identifiers["*"]["*"])) {
                let listeners = array_merge(listeners, this->identifiers["*"]["*"]);
            }
        }

        return listeners;
        */
    }

    /**
     * Clear all listeners for a given identifier, optionally for a specific event
     *
     * @param  string|int  identifier
     * @param  null|string eventName
     * @return void
     */
    public function clearListeners(identifier, eventName = null)
    {
        if !isset this->identifiers[identifier] {
            return null;
        }

        if (eventName === null) {
            unset this->identifiers[identifier];
        }

        unset this->identifiers[identifier][eventName];
    }

    /**
     * Retrieve all registered events for a given resource
     *
     * @param  string|int identifier
     * @return array
     */
    public function getEvents(identifier)
    {
        if !isset this->identifiers[identifier] {

            // Check if there are any id wildcards listeners
            if (identifier !== "*") {
                if isset this->identifiers["*"] {
                    return array_keys(this->identifiers["*"]);
                }
            }

            return false;
        }

        return array_keys(this->identifiers[identifier]);
    }
}
