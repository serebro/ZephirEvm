
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Event manager: notification system
 *
 * Use the EventManager when you want to create a per-instance notification
 * system for your objects.
 */
ZEPHIR_INIT_CLASS(Cyant_EventManager_EventManager) {

	ZEPHIR_REGISTER_CLASS(Cyant\\EventManager, EventManager, cyant, eventmanager_eventmanager, cyant_eventmanager_eventmanager_method_entry, 0);

/**
     * Subscribed events and their listeners
     *
     * @var array
     */
	zend_declare_property_null(cyant_eventmanager_eventmanager_ce, SL("events"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
     * Identifiers, used to pull shared signals from SharedEventManagerInterface instance
     *
     * @var array
     */
	zend_declare_property_null(cyant_eventmanager_eventmanager_ce, SL("identifiers"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
     * Shared event manager
     *
     * @var null|SharedEventManagerInterface
     */
	zend_declare_property_null(cyant_eventmanager_eventmanager_ce, SL("sharedManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(cyant_eventmanager_eventmanager_ce TSRMLS_CC, 1, cyant_eventmanager_eventmanagerinterface_ce);

	return SUCCESS;

}

/**
 * Constructor
 *
 * Allows optionally specifying identifier(s) to use to pull signals from a
 * SharedEventManagerInterface.
 *
 * @param  null|string|int|array|Traversable identifiers
 */
PHP_METHOD(Cyant_EventManager_EventManager, __construct) {

	zval *identifiers = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &identifiers);

	if (!identifiers) {
		identifiers = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("events"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("identifiers"), _1 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "setidentifiers", identifiers);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set shared event manager
 *
 * @param  SharedEventManagerInterface sharedEventManager
 * @return void
 */
PHP_METHOD(Cyant_EventManager_EventManager, setSharedManager) {

	zval *sharedEventManager;

	zephir_fetch_params(0, 1, 0, &sharedEventManager);



	zephir_update_property_this(this_ptr, SL("sharedManager"), sharedEventManager TSRMLS_CC);

}

/**
 * Get shared event manager
 *
 * @return SharedEventManagerInterface|null
 */
PHP_METHOD(Cyant_EventManager_EventManager, getSharedManager) {


	RETURN_MEMBER(this_ptr, "sharedManager");

}

/**
 * Attach a listener to an event
 *
 * The first argument is the event, and the next argument describes a
 * callback that will respond to that event.
 *
 * The last argument indicates a priority at which the event should be
 * executed. By default, this value is 1; however, you may set it for any
 * integer value. Higher values have higher priority (i.e., execute first).
 *
 * You can specify "*" for the event name. In such cases, the listener will
 * be triggered for every event.
 *
 * @param  string   event An event or array of event names
 * @param  listener
 * @param  int      priority If provided, the priority at which to register the callable
 * @return if attaching (to allow later unsubscribe)
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(Cyant_EventManager_EventManager, attach) {

	int priority;
	zval *event_param = NULL, *listener, *priority_param = NULL, *_0, *_1 = NULL, *_2, *_3, _4, *_5, *_6, _7 = zval_used_for_init, *_8 = NULL, *_9, *_10;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event_param, &listener, &priority_param);

		zephir_get_strval(event, event_param);
	if (!priority_param) {
		priority = 1;	} else {
		priority = zephir_get_intval(priority_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, event))) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_array(this_ptr, SL("events"), event, _1 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, event, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, priority);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, &_4, ".0");
	if (!(zephir_array_isset(_3, _5))) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, priority);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_VS(_8, &_7, ".0");
		zephir_array_update_multi(&_6, &_1 TSRMLS_CC, SL("zz"), 2, event, _8);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_array_fetch(&_9, _6, event, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, priority);
	ZEPHIR_INIT_LNVAR(_8);
	ZEPHIR_CONCAT_VS(_8, &_7, ".0");
	zephir_array_fetch(&_10, _9, _8, PH_NOISY | PH_READONLY TSRMLS_CC);
	Z_SET_ISREF_P(_10);
	zephir_call_func_p2_noret("array_push", _10, listener);
	RETURN_CCTOR(listener);

}

/**
 * Attach a listener aggregate
 *
 * Listener aggregates accept an EventManagerInterface instance, and call attach()
 * one or more times, typically to attach to multiple events using local
 * methods.
 *
 * @param  ListenerAggregateInterface aggregate
 * @param  int                        priority If provided, a suggested priority for the aggregate to use
 * @return mixed return value of {@link ListenerAggregateInterface::attach()}
 */
PHP_METHOD(Cyant_EventManager_EventManager, attachAggregate) {

	zval *aggregate, *priority = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregate, &priority);

	if (!priority) {
		ZEPHIR_INIT_VAR(priority);
		ZVAL_LONG(priority, 1);
	}


	zephir_call_method_p2(return_value, aggregate, "attach", this_ptr, priority);
	RETURN_MM();

}

/**
 * Unsubscribe a listener from an event
 *
 * This method is quite inefficient as it needs to traverse each queue, so use with care! If you are that
 * worried about performance, you should always filter by the event name so that less work is done
 *
 * @param  listener
 * @param  string   eventName
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
PHP_METHOD(Cyant_EventManager_EventManager, detach) {

	HashTable *_3, *_6, *_9;
	HashPosition _2, _5, _8;
	zval *listener = NULL, *eventName = NULL, *index = NULL, *listeners = NULL, *key = NULL, *_0, *_1, **_4, *event = NULL, **_7, **_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &listener, &eventName);

	ZEPHIR_SEPARATE_PARAM(listener);
	if (!eventName) {
		eventName = ZEPHIR_GLOBAL(global_null);
	}


	if (!(0 == 0)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		zephir_array_fetch(&_1, _0, eventName, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(index, _3, _2);
			ZEPHIR_GET_HVALUE(listeners, _4);
			ZEPHIR_INIT_NVAR(key);
			zephir_call_func_p3(key, "array_search", listener, listeners, ZEPHIR_GLOBAL(global_true));
			if (!ZEPHIR_IS_FALSE(key)) {
				RETURN_MM_BOOL(1);
			}
		}
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_6, &_5, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(event, _7);
		zephir_is_iterable(event, &_9, &_8, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
			; zend_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(listener, _10);
			ZEPHIR_INIT_NVAR(key);
			zephir_call_func_p3(key, "array_search", listener, listeners, ZEPHIR_GLOBAL(global_true));
			if (!ZEPHIR_IS_FALSE(key)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Detach a listener aggregate
 *
 * Listener aggregates accept an EventManagerInterface instance, and call detach()
 * of all previously attached listeners.
 *
 * @param  ListenerAggregateInterface aggregate
 * @return bool
 */
PHP_METHOD(Cyant_EventManager_EventManager, detachAggregate) {

	zval *aggregate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aggregate);



	zephir_call_method_p1(return_value, aggregate, "detach", this_ptr);
	RETURN_MM();

}

/**
 * Trigger all listeners for a given event (optionally until a callback evaluates to true)
 *
 * @param  string              eventName
 * @param  EventInterface|null event
 * @param  callable|null       callback
 * @return ResponseCollection All listener return values
 */
PHP_METHOD(Cyant_EventManager_EventManager, trigger) {

	zend_function *_11 = NULL, *_16 = NULL, *_17 = NULL;
	HashTable *_6, *_9;
	HashPosition _5, _8;
	zval *eventName_param = NULL, *event = NULL, *callback = NULL, *responses, *listeners, *_0, *_1, *_2, *_3, *_4 = NULL, *lastResponse = NULL, *listenersByPriority = NULL, *listener = NULL, **_7, **_10, *_12 = NULL, *_13 = NULL, *_14 = NULL, _15 = zval_used_for_init, *responseCollection = NULL;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &eventName_param, &event, &callback);

		zephir_get_strval(eventName, eventName_param);
	if (!event) {
		ZEPHIR_CPY_WRT(event, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(event);
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(event) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(event);
		object_init_ex(event, cyant_eventmanager_event_ce);
		zephir_call_method_noret(event, "__construct");
	}
	zephir_call_method_p1_noret(event, "stoppropagation", ZEPHIR_GLOBAL(global_false));
	ZEPHIR_INIT_VAR(responses);
	array_init(responses);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "getlisteners", eventName);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "*", 1);
	zephir_call_method_p1(_1, this_ptr, "getlisteners", _2);
	ZEPHIR_INIT_BNVAR(_2);
	zephir_call_method_p1(_2, this_ptr, "getsharedlisteners", eventName);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "*", 1);
	zephir_call_method_p1(_3, this_ptr, "getsharedlisteners", _4);
	ZEPHIR_INIT_VAR(listeners);
	zephir_call_func_p4(listeners, "array_merge_recursive", _0, _1, _2, _3);
	zephir_is_iterable(listeners, &_6, &_5, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(listenersByPriority, _7);
		zephir_is_iterable(listenersByPriority, &_9, &_8, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
			; zend_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(listener, _10);
			ZEPHIR_INIT_NVAR(lastResponse);
			zephir_call_func_p2(lastResponse, "call_user_func", listener, event);
			zephir_array_append(&responses, lastResponse, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_cache(_4, event, "ispropagationstopped", &_11);
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_INIT_NVAR(_13);
			ZEPHIR_INIT_LNVAR(_14);
			zephir_add_function(_14, _12, _13 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_15);
			zephir_add_function(&_15, _4, _14 TSRMLS_CC);
			if (zephir_is_true(&_15)) {
				ZEPHIR_INIT_NVAR(responseCollection);
				object_init_ex(responseCollection, cyant_eventmanager_responsecollection_ce);
				zephir_call_method_p1_cache_noret(responseCollection, "__construct", &_16, responses);
				zephir_call_method_p1_cache_noret(responseCollection, "setstopped", &_17, ZEPHIR_GLOBAL(global_true));
				RETURN_CCTOR(responseCollection);
			}
		}
	}
	object_init_ex(return_value, cyant_eventmanager_responsecollection_ce);
	zephir_call_method_p1_noret(return_value, "__construct", responses);
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, getEventNames) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_call_func_p1(return_value, "array_keys", _0);
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, getListeners) {

	zval *eventName, *_0, *_1, *_2;

	zephir_fetch_params(0, 1, 0, &eventName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	if (zephir_array_isset(_0, eventName)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, eventName, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTORW(_2);
	}
	array_init(return_value);
	return;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, clearListeners) {

	zval *eventName;

	zephir_fetch_params(0, 1, 0, &eventName);




}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, setIdentifiers) {

	zval *identifiers = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifiers);

	ZEPHIR_SEPARATE_PARAM(identifiers);


	if (zephir_is_instance_of(identifiers, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "iterator_to_array", identifiers);
		ZEPHIR_CPY_WRT(identifiers, _0);
	}
	zephir_update_property_this(this_ptr, SL("identifiers"), identifiers TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, addIdentifiers) {

	zval *identifiers = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifiers);

	ZEPHIR_SEPARATE_PARAM(identifiers);


	if (zephir_is_instance_of(identifiers, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "iterator_to_array", identifiers);
		ZEPHIR_CPY_WRT(identifiers, _0);
	}
	ZEPHIR_INIT_NVAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(identifiers) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "array_unique", _0);
	zephir_update_property_this(this_ptr, SL("identifiers"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, getIdentifiers) {


	RETURN_MEMBER(this_ptr, "identifiers");

}

/**
 * Prepare arguments
 *
 * Use this method if you want to be able to modify arguments from within a
 * listener. It returns an ArrayObject of the arguments, which may then be
 * passed to trigger() or triggerUntil().
 *
 * @param  array args
 * @return ArrayObject
 */
PHP_METHOD(Cyant_EventManager_EventManager, prepareArgs) {

	zend_class_entry *_0;
	zval *args;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args);



	_0 = zend_fetch_class(SL("ArrayObject"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _0);
	zephir_call_method_p1_noret(return_value, "__construct", args);
	RETURN_MM();

}

/**
 * Get list of all listeners attached to the shared event manager for
 * identifiers registered by this instance
 *
 * @param  string eventName
 * @return array
 */
PHP_METHOD(Cyant_EventManager_EventManager, getSharedListeners) {

	zval *eventName, *_0, *identifiers, _1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sharedManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(_0) == IS_NULL)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(identifiers);
	zephir_read_property_this(&identifiers, this_ptr, SL("identifiers"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "*", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p3(_2, "in_array", &_1, identifiers, ZEPHIR_GLOBAL(global_true));
	if (!zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "*", 1);
		zephir_array_append(&identifiers, _3, PH_SEPARATE);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("sharedManager"), PH_NOISY_CC);
	zephir_call_method_p2(return_value, _4, "getlisteners", identifiers, eventName);
	RETURN_MM();

}

