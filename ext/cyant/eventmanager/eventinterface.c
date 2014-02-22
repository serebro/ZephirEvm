
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
 * Representation of an event
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_EventInterface) {

	ZEPHIR_REGISTER_INTERFACE(Cyant\\EventManager, EventInterface, cyant, eventmanager_eventinterface, cyant_eventmanager_eventinterface_method_entry);

	return SUCCESS;

}

/**
 * Set the event target/context
 *
 * @param  null|string|object target
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, setTarget);

/**
 * Get target/context from which event was triggered
 *
 * @return null|string|object
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, getTarget);

/**
 * Set event parameters (overwrite parameters)
 *
 * @param  array|Traversable params
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, setParams);

/**
 * Set a single parameter by key
 *
 * @param  string name
 * @param  mixed  value
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, setParam);

/**
 * Get parameters passed to the event
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, getParams);

/**
 * Get a single parameter by name
 *
 * @param  string name
 * @param  mixed  default Default value to return if parameter does not exist
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, getParam);

/**
 * Indicate whether or not the parent EventManagerInterface should stop propagating events
 *
 * @param  bool flag
 * @return void
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, stopPropagation);

/**
 * Has this event indicated event propagation should stop?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Cyant_EventManager_EventInterface, isPropagationStopped);

