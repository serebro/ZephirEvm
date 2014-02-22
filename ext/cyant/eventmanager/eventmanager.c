
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


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

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(cyant_eventmanager_eventmanager_ce, SL("orderedByPriority"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

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

	int ZEPHIR_LAST_CALL_STATUS;
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
	zephir_check_call_status();
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



	if (!(zephir_instance_of_ev(sharedEventManager, cyant_eventmanager_sharedeventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STRW(spl_ce_InvalidArgumentException, "Parameter 'sharedEventManager' must be an instance of 'Cyant\\EventManager\\SharedEventManagerInterface'");
		return;
	}
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

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *listener, *priority_param = NULL, *_0, *_1 = NULL, *_2, *_3, _4, *_6, _7 = zval_used_for_init, *_9, *_10;
	zval *event = NULL, *_5, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event_param, &listener, &priority_param);

	zephir_get_strval(event, event_param);
	if (!priority_param) {
		priority = 1;
	} else {
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
	zephir_check_call_status();
	Z_UNSET_ISREF_P(_10);
	zephir_update_property_this(this_ptr, SL("orderedByPriority"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate, *priority = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregate, &priority);

	if (!priority) {
		ZEPHIR_INIT_VAR(priority);
		ZVAL_LONG(priority, 1);
	}


	if (!(zephir_instance_of_ev(aggregate, cyant_eventmanager_listeneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'Cyant\\EventManager\\ListenerAggregateInterface'");
		return;
	}
	zephir_call_method_p2(return_value, aggregate, "attach", this_ptr, priority);
	zephir_check_call_status();
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

	zval *eventName = NULL;
	zval *listener, *eventName_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &listener, &eventName_param);

	if (!eventName_param) {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	} else {
		zephir_get_strval(eventName, eventName_param);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aggregate);



	if (!(zephir_instance_of_ev(aggregate, cyant_eventmanager_listeneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'Cyant\\EventManager\\ListenerAggregateInterface'");
		return;
	}
	zephir_call_method_p1(return_value, aggregate, "detach", this_ptr);
	zephir_check_call_status();
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

	zend_function *_8 = NULL, *_12 = NULL, *_13 = NULL;
	HashTable *_2, *_5;
	HashPosition _1, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _9, _10;
	zval *eventName_param = NULL, *event = NULL, *callback = NULL, *responses, *listeners, *lastResponse = NULL, *listenersByPriority = NULL, *listener = NULL, **_3, **_6, *_7 = NULL, *_11 = NULL, *responseCollection = NULL;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &eventName_param, &event, &callback);

	if (Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(eventName_param) == IS_STRING) {
		eventName = eventName_param;
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}
	if (!event) {
		ZEPHIR_CPY_WRT(event, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(event);
	}
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(event) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(event, cyant_eventmanager_eventinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Cyant\\EventManager\\EventInterface'");
		return;
	}
	if ((Z_TYPE_P(event) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(event);
		object_init_ex(event, cyant_eventmanager_event_ce);
		zephir_call_method_noret(event, "__construct");
		zephir_check_call_status();
	}
	zephir_call_method_p1_noret(event, "stoppropagation", ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(responses);
	array_init(responses);
	ZEPHIR_INIT_VAR(listeners);
	zephir_call_method_p1(listeners, this_ptr, "getlisteners", eventName);
	zephir_check_call_status();
	zephir_is_iterable(listeners, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(listenersByPriority, _3);
		zephir_is_iterable(listenersByPriority, &_5, &_4, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(listener, _6);
			ZEPHIR_INIT_NVAR(lastResponse);
			zephir_call_func_p1(lastResponse, "listener", event);
			zephir_check_call_status();
			zephir_array_append(&responses, lastResponse, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_cache(_7, event, "ispropagationstopped", &_8);
			zephir_check_call_status();
			_9 = zephir_is_true(_7);
			if (!(_9)) {
				_10 = zephir_is_true(callback);
				if (_10) {
					ZEPHIR_INIT_NVAR(_11);
					zephir_call_func_p1(_11, (Z_TYPE_P(callback) == IS_STRING ? Z_STRVAL_P(callback) : ""), lastResponse);
					zephir_check_call_status();
					_10 = zephir_is_true(_11);
				}
				_9 = _10;
			}
			if (_9) {
				ZEPHIR_INIT_NVAR(responseCollection);
				object_init_ex(responseCollection, cyant_eventmanager_responsecollection_ce);
				zephir_call_method_p1_cache_noret(responseCollection, "__construct", &_12, responses);
				zephir_check_call_status();
				zephir_call_method_p1_cache_noret(responseCollection, "setstopped", &_13, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				RETURN_CCTOR(responseCollection);
			}
		}
	}
	object_init_ex(return_value, cyant_eventmanager_responsecollection_ce);
	zephir_call_method_p1_noret(return_value, "__construct", responses);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, getEventNames) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, getListeners) {

	int ZEPHIR_LAST_CALL_STATUS, mergeCount = 0;
	HashTable *_3;
	HashPosition _2;
	zval *eventName, *listeners = NULL, *wildcardListeners = NULL, *sharedListeners, *_0, *name = NULL, *listenersByPriority = NULL, *_1, **_4, *_5, *_6, *_7 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName);



	ZEPHIR_INIT_VAR(listeners);
	array_init(listeners);
	ZEPHIR_INIT_VAR(wildcardListeners);
	array_init(wildcardListeners);
	ZEPHIR_INIT_VAR(sharedListeners);
	array_init(sharedListeners);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderedByPriority"), PH_NOISY_CC);
	if (!zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(name, _3, _2);
			ZEPHIR_GET_HVALUE(listenersByPriority, _4);
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
			zephir_array_fetch(&_6, _5, name, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 1);
			Z_SET_ISREF_P(_6);
			zephir_call_func_p2_noret("krsort", _6, _7);
			zephir_check_call_status();
			Z_UNSET_ISREF_P(_6);
		}
		zephir_update_property_this(this_ptr, SL("orderedByPriority"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	if (zephir_array_isset(_1, eventName)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(listeners);
		zephir_array_fetch(&listeners, _5, eventName, PH_NOISY TSRMLS_CC);
		if (zephir_is_true(listeners)) {
			mergeCount++;
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("*"))) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(wildcardListeners);
		zephir_array_fetch_string(&wildcardListeners, _5, SL("*"), PH_NOISY TSRMLS_CC);
		if (zephir_is_true(wildcardListeners)) {
			mergeCount++;
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sharedManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(_1) != IS_NULL)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("sharedManager"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(sharedListeners);
		zephir_call_method_p2(sharedListeners, _5, "getlisteners", _8, eventName);
		zephir_check_call_status();
		if (zephir_is_true(sharedListeners)) {
			mergeCount++;
		}
	}
	if ((mergeCount > 1)) {
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_func_p3(_7, "array_merge_recursive", listeners, wildcardListeners, sharedListeners);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(listeners, _7);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 1);
		Z_SET_ISREF_P(listeners);
		zephir_call_func_p2_noret("krsort", listeners, _7);
		zephir_check_call_status();
		Z_UNSET_ISREF_P(listeners);
	} else {
		if (zephir_is_true(wildcardListeners)) {
			ZEPHIR_CPY_WRT(listeners, wildcardListeners);
		} else {
			if (zephir_is_true(sharedListeners)) {
				ZEPHIR_CPY_WRT(listeners, sharedListeners);
			}
		}
	}
	RETURN_CCTOR(listeners);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, clearListeners) {

	zval *eventName, *_0;

	zephir_fetch_params(0, 1, 0, &eventName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_array_unset(&_0, eventName, PH_SEPARATE);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, setIdentifiers) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifiers = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifiers);

	ZEPHIR_SEPARATE_PARAM(identifiers);


	if (zephir_is_instance_of(identifiers, SL("Cyant\\EventManager\\Traversable") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "iterator_to_array", identifiers);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(identifiers, _0);
	}
	zephir_update_property_this(this_ptr, SL("identifiers"), identifiers TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Cyant_EventManager_EventManager, addIdentifiers) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifiers = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifiers);

	ZEPHIR_SEPARATE_PARAM(identifiers);


	if (zephir_is_instance_of(identifiers, SL("Cyant\\EventManager\\Traversable") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "iterator_to_array", identifiers);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(identifiers, _0);
	}
	ZEPHIR_INIT_NVAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(identifiers) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "array_unique", _0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *args;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args);



	_0 = zend_fetch_class(SL("Cyant\\EventManager\\ArrayObject"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		zephir_call_method_p1_noret(return_value, "__construct", args);
		zephir_check_call_status();
	}
	RETURN_MM();

}

