
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


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

	HashTable *_2;
	HashPosition _1;
	int priority;
	zval *eventName = NULL;
	zval *identifiers = NULL, *eventName_param = NULL, *listener, *priority_param = NULL, *identifier = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &identifiers, &eventName_param, &listener, &priority_param);

	ZEPHIR_SEPARATE_PARAM(identifiers);
		zephir_get_strval(eventName, eventName_param);
	if (!priority_param || Z_TYPE_P(priority_param) == IS_NULL) {
		priority = 1;	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_string", identifiers);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(identifiers);
		array_init(identifiers);
		zephir_array_fast_append(identifiers, identifiers);
	}
	zephir_is_iterable(identifiers, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(identifier, _3);
		if (0) {
		}
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

	int priority;
	zval *aggregate, *priority_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregate, &priority_param);

	if (!priority_param || Z_TYPE_P(priority_param) == IS_NULL) {
		priority = 1;	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	zephir_call_method_p2(return_value, aggregate, "attachshared", this_ptr, _0);
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

	zval *identifier, *listener, *_0;

	zephir_fetch_params(0, 2, 0, &identifier, &listener);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset(_0, identifier)) {
	}
	RETURN_BOOL(0);

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

	zval *aggregate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aggregate);



	zephir_call_method_p1(return_value, aggregate, "detachshared", this_ptr);
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

	zval *identifiers, *eventName;

	zephir_fetch_params(0, 2, 0, &identifiers, &eventName);




}

/**
 * Clear all listeners for a given identifier, optionally for a specific event
 *
 * @param  string|int  identifier
 * @param  null|string eventName
 * @return void
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, clearListeners) {

	zval *identifier, *eventName = NULL, *_0;

	zephir_fetch_params(0, 1, 1, &identifier, &eventName);

	if (!eventName || Z_TYPE_P(eventName) == IS_NULL) {
		eventName = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, identifier))) {
		RETURN_NULL();
	}
	if ((Z_TYPE_P(eventName) == IS_NULL)) {
	}

}

/**
 * Retrieve all registered events for a given resource
 *
 * @param  string|int identifier
 * @return array
 */
PHP_METHOD(Cyant_EventManager_SharedEventManager, getEvents) {

	zval *identifier, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, identifier))) {
		if (!ZEPHIR_IS_STRING(identifier, "*")) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
			if (zephir_array_isset_string(_1, SS("*"))) {
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
				zephir_array_fetch_string(&_3, _2, SL("*"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_call_func_p1(return_value, "array_keys", _3);
				RETURN_MM();
			}
		}
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, identifier, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_call_func_p1(return_value, "array_keys", _2);
	RETURN_MM();

}

