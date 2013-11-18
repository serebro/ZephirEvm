
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Collection of signal handler return values
 *
 * We used to use a SplStack in Zend Framework 2, but using an array allows us some interesting
 * optimizations
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_ResponseCollection) {

	ZEPHIR_REGISTER_CLASS(Cyant\\EventManager, ResponseCollection, cyant, eventmanager_responsecollection, cyant_eventmanager_responsecollection_method_entry, 0);

/**
     * @var array
     */
	zend_declare_property_null(cyant_eventmanager_responsecollection_ce, SL("responses"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
     * @var bool
     */
	zend_declare_property_bool(cyant_eventmanager_responsecollection_ce, SL("stopped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param array responses
 */
PHP_METHOD(Cyant_EventManager_ResponseCollection, __construct) {

	zval *responses = NULL, *_0, _1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &responses);

	if (!responses) {
		ZEPHIR_CPY_WRT(responses, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(responses);


	if ((Z_TYPE_P(responses) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(responses);
		array_init(responses);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_array", responses);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "First argument must be an array", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 256);
		zephir_call_func_p2_noret("trigger_error", &_1, &_2);
	}
	zephir_update_property_this(this_ptr, SL("responses"), responses TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Did the last response provided trigger a short circuit of the stack?
 *
 * @return bool
 */
PHP_METHOD(Cyant_EventManager_ResponseCollection, stopped) {


	RETURN_MEMBER(this_ptr, "stopped");

}

/**
 * Mark the collection as stopped (or its opposite)
 *
 * @param  bool flag
 * @return void
 */
PHP_METHOD(Cyant_EventManager_ResponseCollection, setStopped) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 1, 0, &flag_param);

		flag = zephir_get_boolval(flag_param);


	zephir_update_property_this(this_ptr, SL("stopped"), flag ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Convenient access to the first handler return value.
 *
 * @return mixed The first handler return value
 */
PHP_METHOD(Cyant_EventManager_ResponseCollection, first) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("responses"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	zephir_call_func_p1_noret("reset", _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("responses"), PH_NOISY_CC);
	Z_SET_ISREF_P(_1);
	zephir_call_func_p1(return_value, "current", _1);
	RETURN_MM();

}

/**
 * Convenient access to the last handler return value.
 *
 * If the collection is empty, returns null. Otherwise, returns value
 * returned by last handler.
 *
 * @return mixed The last handler return value
 */
PHP_METHOD(Cyant_EventManager_ResponseCollection, last) {

	zval *last, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("responses"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_INIT_VAR(last);
	zephir_call_func_p1(last, "end", _0);
	if (ZEPHIR_IS_FALSE(last)) {
		RETURN_MM_NULL();
	} else {
		RETURN_CCTOR(last);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if any of the responses match the given value.
 *
 * @param  mixed value The value to look for among responses
 * @return bool
 */
PHP_METHOD(Cyant_EventManager_ResponseCollection, contains) {

	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("responses"), PH_NOISY_CC);
	zephir_call_func_p3(return_value, "in_array", value, _0, ZEPHIR_GLOBAL(global_true));
	RETURN_MM();

}

