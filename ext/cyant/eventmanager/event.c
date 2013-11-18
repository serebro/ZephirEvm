
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Representation of an event
 *
 * Encapsulates the target context and parameters passed, and provides some
 * behavior for interacting with the event manager.
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_Event) {

	ZEPHIR_REGISTER_CLASS(Cyant\\EventManager, Event, cyant, eventmanager_event, cyant_eventmanager_event_method_entry, 0);

/**
     * @var string|object The event target
     */
	zend_declare_property_null(cyant_eventmanager_event_ce, SL("target"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
     * @var array The event parameters
     */
	zend_declare_property_null(cyant_eventmanager_event_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
     * @var bool Whether or not to stop propagation
     */
	zend_declare_property_bool(cyant_eventmanager_event_ce, SL("stopPropagation"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(cyant_eventmanager_event_ce TSRMLS_CC, 1, cyant_eventmanager_eventinterface_ce);

	return SUCCESS;

}

/**
 * Constructor
 *
 * Accept a target and its parameters.
 *
 * @param  string|object     target
 * @param  array|Traversable params
 */
PHP_METHOD(Cyant_EventManager_Event, __construct) {

	zval *target = NULL, *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &target, &params);

	if (!target) {
		target = ZEPHIR_GLOBAL(global_null);
	}
	if (!params) {
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(params);


	ZEPHIR_INIT_BNVAR(params);
	array_init(params);
	zephir_call_method_p1_noret(this_ptr, "settarget", target);
	if ((Z_TYPE_P(params) != IS_NULL)) {
		zephir_call_method_p1_noret(this_ptr, "setparams", params);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, setTarget) {

	zval *target;

	zephir_fetch_params(0, 1, 0, &target);



	zephir_update_property_this(this_ptr, SL("target"), target TSRMLS_CC);

}

/**
 * {@inheritDoc}
 *
 * This may be either an object, or the name of a static method.
 */
PHP_METHOD(Cyant_EventManager_Event, getTarget) {


	RETURN_MEMBER(this_ptr, "target");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, setParams) {

	zval *params = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);

	ZEPHIR_SEPARATE_PARAM(params);


	if (zephir_is_instance_of(params, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "iterator_to_array", params);
		ZEPHIR_CPY_WRT(params, _0);
	}
	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, setParam) {

	zval *name, *value;

	zephir_fetch_params(0, 2, 0, &name, &value);



	zephir_update_property_array(this_ptr, SL("params"), name, value TSRMLS_CC);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, getParams) {


	RETURN_MEMBER(this_ptr, "params");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, getParam) {

	zval *name, *def = NULL, *_0, *_1, *_2;

	zephir_fetch_params(0, 1, 1, &name, &def);

	if (!def) {
		def = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, name, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTORW(_2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, name, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTORW(_2);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, stopPropagation) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 0, 1, &flag_param);

	if (!flag_param) {
		flag = 1;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	zephir_update_property_this(this_ptr, SL("stopPropagation"), flag ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_Event, isPropagationStopped) {


	RETURN_MEMBER(this_ptr, "stopPropagation");

}

