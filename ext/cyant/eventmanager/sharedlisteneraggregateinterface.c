
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
 * Interface for self-registering event listeners.
 *
 * Classes implementing this interface may be registered by name or instance
 * with an SharedEventManager, without an event name. The {@link attach()} method will
 * then be called with the current SharedEventManager instance, allowing the class to
 * wire up one or more listeners.
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_SharedListenerAggregateInterface) {

	ZEPHIR_REGISTER_INTERFACE(Cyant\\EventManager, SharedListenerAggregateInterface, cyant, eventmanager_sharedlisteneraggregateinterface, cyant_eventmanager_sharedlisteneraggregateinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach one or more listeners
 *
 * Implementors may add an optional priority argument; the SharedEventManager
 * implementation will pass this to the aggregate.
 *
 * @param SharedEventManagerInterface events
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedListenerAggregateInterface, attachShared);

/**
 * Detach all previously attached listeners
 *
 * @param SharedEventManagerInterface events
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_SharedListenerAggregateInterface, detachShared);

