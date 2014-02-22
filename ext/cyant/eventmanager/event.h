
extern zend_class_entry *cyant_eventmanager_event_ce;

ZEPHIR_INIT_CLASS(Cyant_EventManager_Event);

PHP_METHOD(Cyant_EventManager_Event, __construct);
PHP_METHOD(Cyant_EventManager_Event, setTarget);
PHP_METHOD(Cyant_EventManager_Event, getTarget);
PHP_METHOD(Cyant_EventManager_Event, setParams);
PHP_METHOD(Cyant_EventManager_Event, setParam);
PHP_METHOD(Cyant_EventManager_Event, getParams);
PHP_METHOD(Cyant_EventManager_Event, getParam);
PHP_METHOD(Cyant_EventManager_Event, stopPropagation);
PHP_METHOD(Cyant_EventManager_Event, isPropagationStopped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_event___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_event_settarget, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_event_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_event_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_event_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_event_stoppropagation, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(cyant_eventmanager_event_method_entry) {
	PHP_ME(Cyant_EventManager_Event, __construct, arginfo_cyant_eventmanager_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Cyant_EventManager_Event, setTarget, arginfo_cyant_eventmanager_event_settarget, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, getTarget, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, setParams, arginfo_cyant_eventmanager_event_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, setParam, arginfo_cyant_eventmanager_event_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, getParam, arginfo_cyant_eventmanager_event_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, stopPropagation, arginfo_cyant_eventmanager_event_stoppropagation, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_Event, isPropagationStopped, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
