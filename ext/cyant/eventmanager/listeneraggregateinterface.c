
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
 * with an EventManager, without an event name. The {@link attach()} method will
 * then be called with the current EventManager instance, allowing the class to
 * wire up one or more listeners.
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_ListenerAggregateInterface) {

	ZEPHIR_REGISTER_INTERFACE(Cyant\\EventManager, ListenerAggregateInterface, cyant, eventmanager_listeneraggregateinterface, cyant_eventmanager_listeneraggregateinterface_method_entry);


	return SUCCESS;

}

/**
 * Attach one or more listeners
 *
 * Implementors may add an optional priority argument; the EventManager
 * implementation will pass this to the aggregate.
 *
 * @param EventManagerInterface events
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_ListenerAggregateInterface, attach);

/**
 * Detach all previously attached listeners
 *
 * @param EventManagerInterface events
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_ListenerAggregateInterface, detach);

