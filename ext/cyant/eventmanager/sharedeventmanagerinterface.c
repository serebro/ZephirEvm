
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Interface for shared event listener collections
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_SharedEventManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Cyant\\EventManager, SharedEventManagerInterface, cyant, eventmanager_sharedeventmanagerinterface, cyant_eventmanager_sharedeventmanagerinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach a listener to an event
 *
 * @param  array    identifiers Identifier(s) for event emitting component(s)
 * @param  string   eventName
 * @param  callable listener PHP Callback
 * @param  int      priority Priority at which listener should execute
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, attach);

/**
 * Attach a listener aggregate
 *
 * @param  SharedListenerAggregateInterface aggregate
 * @param  int priority If provided, a suggested priority for the aggregate to use
 * @return mixed return value of {@link SharedListenerAggregateInterface::attachShared()}
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, attachAggregate);

/**
 * Detach a listener from an event offered by a given resource
 *
 * @param  string|int identifier
 * @param  callable   listener
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, detach);

/**
 * Detach a listener aggregate
 *
 * @param  SharedListenerAggregateInterface aggregate
 * @return mixed return value of {@link SharedListenerAggregateInterface::detachShared()}
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, detachAggregate);

/**
 * Retrieve all listeners for a given identifier (or multiple identifiers) and event
 *
 * @param  string|string[] identifiers
 * @param  string|int      eventName
 * @return array
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, getListeners);

/**
 * Clear all listeners for a given identifier, optionally for a specific event
 *
 * @param  string|int  identifier
 * @param  null|string eventName
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, clearListeners);

/**
 * Retrieve all registered events for a given resource
 *
 * @param  string|int identifier
 * @return array
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedEventManagerInterface, getEvents);

