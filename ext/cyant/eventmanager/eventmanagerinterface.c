
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Cyant Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Cyant Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Interface for messengers
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_EventManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(Cyant\\EventManager, EventManagerInterface, cyant, eventmanager_eventmanagerinterface, cyant_eventmanager_sharedeventmanagerawareinterface_ce, cyant_eventmanager_eventmanagerinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach a listener to an event
 *
 * @param  string   event
 * @param  listener
 * @param  int      priority Priority at which to register listener
 * @return callable
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, attach);

/**
 * Attach a listener aggregate
 *
 * @param  ListenerAggregateInterface aggregate
 * @param  int                        priority If provided, a suggested priority for the aggregate to use
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, attachAggregate);

/**
 * Detach an event listener
 *
 * @param  listener
 * @param  string   eventName optional to speed up process
 * @return bool
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, detach);

/**
 * Detach a listener aggregate
 *
 * @param  ListenerAggregateInterface aggregate
 * @return bool
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, detachAggregate);

/**
 * Trigger an event (optionally until using a callback returns a boolean true)
 *
 * @param  string              eventName
 * @param  EventInterface|null event
 * @param  callable|null       callback
 * @return ResponseCollection
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, trigger);

/**
 * Get a list of event names for which this collection has listeners
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, getEventNames);

/**
 * Retrieve a list of listeners registered to a given event
 *
 * @param  string eventName
 * @return array
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, getListeners);

/**
 * Clear all listeners for a given event
 *
 * @param  string eventName
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, clearListeners);

/**
 * Set the identifiers (overrides any currently set identifiers)
 *
 * @param  array|Traversable identifiers
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, setIdentifiers);

/**
 * Add some identifier(s) (appends to any currently set identifiers)
 *
 * @param  array|Traversable identifiers
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, addIdentifiers);

/**
 * Get the identifier(s) for this EventManager
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventManagerInterface, getIdentifiers);

