
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Shared/contextual EventManager
 *
 * Allows attaching to EMs composed by other classes without having an instance first.
 * The assumption is that the SharedEventManager will be injected into EventManager
 * instances, and then queried for additional listeners when triggering an event.
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_SharedEventManager) {

	ZEPHIR_REGISTER_CLASS(Cyant\\EventManager, SharedEventManager, cyant, eventmanager_sharedeventmanager, cyant_eventmanager_sharedeventmanager_method_entry, 0);

	/**
	 * Identifiers that are mapped to listeners
	 *
	 * @var array
	 */
	zend_declare_property_null(cyant_eventmanager_sharedeventmanager_ce, SL("identifiers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(cyant_eventmanager_sharedeventmanager_ce TSRMLS_CC, 1, cyant_eventmanager_sharedeventmanagerinterface_ce);
	return SUCCESS;

}

/**
 * Stupid zephir does not support default values with array....
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("identifiers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Cyant_EventManager_SharedEventManager, attach) {

	HashTable *_1;
	HashPosition _0;
	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *eventName = NULL, *_11 = NULL, *_14 = NULL;
	zval *identifiers = NULL, *eventName_param = NULL, *listener, *priority_param = NULL, *key = NULL, **_2, *_3, *_4 = NULL, *_5, *_6, *_7, *_8, *_9, _10 = zval_used_for_init, *_12, _13 = zval_used_for_init, *_15, *_16, *_17;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &identifiers, &eventName_param, &listener, &priority_param);

	ZEPHIR_SEPARATE_PARAM(identifiers);
	zephir_get_strval(eventName, eventName_param);
	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (Z_TYPE_P(identifiers) == IS_STRING) {
		ZEPHIR_INIT_NVAR(identifiers);
		array_init_size(identifiers, 2);
		zephir_array_fast_append(identifiers, identifiers);
	}
	zephir_is_iterable(identifiers, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(key, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		if (!(zephir_array_isset(_3, key))) {
			ZEPHIR_INIT_NVAR(_4);
			array_init(_4);
			zephir_update_property_array(this_ptr, SL("identifiers"), key, _4 TSRMLS_CC);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_fetch(&_6, _5, key, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (!(zephir_array_isset(_6, eventName))) {
			ZEPHIR_INIT_NVAR(_4);
			array_init(_4);
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			zephir_array_update_multi(&_7, &_4 TSRMLS_CC, SL("zz"), 2, key, eventName);
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_fetch(&_8, _7, key, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch(&_9, _8, eventName, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, priority);
		ZEPHIR_INIT_LNVAR(_11);
		ZEPHIR_CONCAT_VS(_11, &_10, ".0");
		if (!(zephir_array_isset(_9, _11))) {
			ZEPHIR_INIT_NVAR(_4);
			array_init(_4);
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_13);
			ZVAL_LONG(&_13, priority);
			ZEPHIR_INIT_LNVAR(_14);
			ZEPHIR_CONCAT_VS(_14, &_13, ".0");
			zephir_array_update_multi(&_12, &_4 TSRMLS_CC, SL("zzz"), 3, key, eventName, _14);
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_fetch(&_15, _7, key, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch(&_16, _15, eventName, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, priority);
		ZEPHIR_INIT_LNVAR(_14);
		ZEPHIR_CONCAT_VS(_14, &_13, ".0");
		zephir_array_fetch(&_17, _16, _14, PH_NOISY | PH_READONLY TSRMLS_CC);
		Z_SET_ISREF_P(_17);
		zephir_call_func_p2_noret("array_push", _17, listener);
		zephir_check_call_status();
		Z_UNSET_ISREF_P(_17);
	}
	RETURN_CCTOR(listener);

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
PHP_METHOD(Cyant_EventManager_SharedEventManager, attachAggregate) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate, *priority_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregate, &priority_param);

	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (!(zephir_is_instance_of(aggregate, SL("Cyant\\EventManager\\Cyant\\EventManager\\SharedListenerAggregateInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'Cyant\\EventManager\\Cyant\\EventManager\\SharedListenerAggregateInterface'");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	zephir_call_method_p2(return_value, aggregate, "attachshared", this_ptr, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Detach a listener from an event offered by a given resource
 *
 * @param  string|int identifier
 * @param  callable   listener
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, detach) {

	zend_function *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_4, *_7;
	HashPosition _3, _6;
	zval *identifier, *listener, *_0, *key = NULL, *event = NULL, *listeners = NULL, *_1, *_2, **_5, **_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier, &listener);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset(_0, identifier)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_is_iterable(_2, &_4, &_3, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(event, _5);
			zephir_is_iterable(event, &_7, &_6, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HVALUE(listeners, _8);
				ZEPHIR_INIT_NVAR(key);
				ZEPHIR_CALL_INTERNAL_FUNCTION(key, &key, "array_search", &_9, 3, listener, listeners, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE(key)) {
					zephir_array_unset(&listeners, key, PH_SEPARATE);
					RETURN_MM_BOOL(1);
				}
			}
		}
	}
	RETURN_MM_BOOL(0);

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
PHP_METHOD(Cyant_EventManager_SharedEventManager, detachAggregate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aggregate);



	if (!(zephir_is_instance_of(aggregate, SL("Cyant\\EventManager\\Cyant\\EventManager\\SharedListenerAggregateInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'Cyant\\EventManager\\Cyant\\EventManager\\SharedListenerAggregateInterface'");
		return;
	}
	zephir_call_method_p1(return_value, aggregate, "detachshared", this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve all listeners for a given identifier and event
 *
 * @param  string|string[] identifiers
 * @param  string|int      eventName
 * @return array
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, getListeners) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *identifiers, *eventName, *listeners = NULL, *identifier = NULL, **_2, *_3, *_4, *_5 = NULL, *_6, *_7, *_8, *_9, *_10, _11, *_12, *_13, *_14, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifiers, &eventName);



	ZEPHIR_INIT_VAR(listeners);
	array_init(listeners);
	zephir_is_iterable(identifiers, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(identifier, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_fetch(&_4, _3, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_array_isset(_4, eventName)) {
			ZEPHIR_INIT_NVAR(_5);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			zephir_array_fetch(&_7, _6, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch(&_8, _7, eventName, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_fast_array_merge(_5, &(listeners), &(_8) TSRMLS_CC);
			ZEPHIR_CPY_WRT(listeners, _5);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_fetch(&_7, _6, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_array_isset_string(_7, SS("*"))) {
			ZEPHIR_INIT_NVAR(_5);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			zephir_array_fetch(&_8, _9, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_10, _8, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_fast_array_merge(_5, &(listeners), &(_10) TSRMLS_CC);
			ZEPHIR_CPY_WRT(listeners, _5);
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset_string(_3, SS("*"))) {
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_STRING(&_11, "*", 0);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p3(_5, "in_array", &_11, identifiers, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			zephir_array_fetch_string(&_4, _6, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
			if (zephir_array_isset(_4, eventName)) {
				ZEPHIR_INIT_NVAR(_5);
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
				zephir_array_fetch_string(&_7, _9, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch(&_8, _7, eventName, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_fast_array_merge(_5, &(listeners), &(_8) TSRMLS_CC);
				ZEPHIR_CPY_WRT(listeners, _5);
			}
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			zephir_array_fetch_string(&_10, _12, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
			if (zephir_array_isset_string(_10, SS("*"))) {
				ZEPHIR_INIT_NVAR(_5);
				_13 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
				zephir_array_fetch_string(&_14, _13, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_string(&_15, _14, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_fast_array_merge(_5, &(listeners), &(_15) TSRMLS_CC);
				ZEPHIR_CPY_WRT(listeners, _5);
			}
		}
	}
	RETURN_CCTOR(listeners);

}

/**
 * Clear all listeners for a given identifier, optionally for a specific event
 *
 * @param  string|int  identifier
 * @param  null|string eventName
 * @return void
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, clearListeners) {

	zval *identifier, *eventName = NULL, *_0, *_1, *_2;

	zephir_fetch_params(0, 1, 1, &identifier, &eventName);

	if (!eventName) {
		eventName = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, identifier))) {
		RETURN_NULL();
	}
	if ((Z_TYPE_P(eventName) == IS_NULL)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_unset(&_1, identifier, PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_unset(&_2, eventName, PH_SEPARATE);

}

/**
 * Retrieve all registered events for a given resource
 *
 * @param  string|int identifier
 * @return array
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, getEvents) {

	zval *identifier, *_0, *_1, *_2, *_3;

	zephir_fetch_params(0, 1, 0, &identifier);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, identifier))) {
		if (!ZEPHIR_IS_STRING(identifier, "*")) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			if (zephir_array_isset_string(_1, SS("*"))) {
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
				zephir_array_fetch_string(&_3, _2, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_keys(return_value, _3 TSRMLS_CC);
				return;
			}
		}
		RETURN_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _1, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_keys(return_value, _3 TSRMLS_CC);
	return;

}

