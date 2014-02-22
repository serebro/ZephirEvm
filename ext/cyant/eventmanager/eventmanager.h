
extern zend_class_entry *cyant_eventmanager_eventmanager_ce;

ZEPHIR_INIT_CLASS(Cyant_EventManager_EventManager);

PHP_METHOD(Cyant_EventManager_EventManager, __construct);
PHP_METHOD(Cyant_EventManager_EventManager, setSharedManager);
PHP_METHOD(Cyant_EventManager_EventManager, getSharedManager);
PHP_METHOD(Cyant_EventManager_EventManager, attach);
PHP_METHOD(Cyant_EventManager_EventManager, attachAggregate);
PHP_METHOD(Cyant_EventManager_EventManager, detach);
PHP_METHOD(Cyant_EventManager_EventManager, detachAggregate);
PHP_METHOD(Cyant_EventManager_EventManager, trigger);
PHP_METHOD(Cyant_EventManager_EventManager, getEventNames);
PHP_METHOD(Cyant_EventManager_EventManager, getListeners);
PHP_METHOD(Cyant_EventManager_EventManager, clearListeners);
PHP_METHOD(Cyant_EventManager_EventManager, setIdentifiers);
PHP_METHOD(Cyant_EventManager_EventManager, addIdentifiers);
PHP_METHOD(Cyant_EventManager_EventManager, getIdentifiers);
PHP_METHOD(Cyant_EventManager_EventManager, prepareArgs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, identifiers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_setsharedmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, sharedEventManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_attachaggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, aggregate)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_detach, 0, 0, 1)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_detachaggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, aggregate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_trigger, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_setidentifiers, 0, 0, 1)
	ZEND_ARG_INFO(0, identifiers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_addidentifiers, 0, 0, 1)
	ZEND_ARG_INFO(0, identifiers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventmanager_prepareargs, 0, 0, 1)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(cyant_eventmanager_eventmanager_method_entry) {
	PHP_ME(Cyant_EventManager_EventManager, __construct, arginfo_cyant_eventmanager_eventmanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Cyant_EventManager_EventManager, setSharedManager, arginfo_cyant_eventmanager_eventmanager_setsharedmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, getSharedManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, attach, arginfo_cyant_eventmanager_eventmanager_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, attachAggregate, arginfo_cyant_eventmanager_eventmanager_attachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, detach, arginfo_cyant_eventmanager_eventmanager_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, detachAggregate, arginfo_cyant_eventmanager_eventmanager_detachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, trigger, arginfo_cyant_eventmanager_eventmanager_trigger, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, getEventNames, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, getListeners, arginfo_cyant_eventmanager_eventmanager_getlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, clearListeners, arginfo_cyant_eventmanager_eventmanager_clearlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, setIdentifiers, arginfo_cyant_eventmanager_eventmanager_setidentifiers, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, addIdentifiers, arginfo_cyant_eventmanager_eventmanager_addidentifiers, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, getIdentifiers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_EventManager, prepareArgs, arginfo_cyant_eventmanager_eventmanager_prepareargs, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
