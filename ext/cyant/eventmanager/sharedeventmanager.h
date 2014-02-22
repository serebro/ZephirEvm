
extern zend_class_entry *cyant_eventmanager_sharedeventmanager_ce;

ZEPHIR_INIT_CLASS(Cyant_EventManager_SharedEventManager);

PHP_METHOD(Cyant_EventManager_SharedEventManager, __construct);
PHP_METHOD(Cyant_EventManager_SharedEventManager, attach);
PHP_METHOD(Cyant_EventManager_SharedEventManager, attachAggregate);
PHP_METHOD(Cyant_EventManager_SharedEventManager, detach);
PHP_METHOD(Cyant_EventManager_SharedEventManager, detachAggregate);
PHP_METHOD(Cyant_EventManager_SharedEventManager, getListeners);
PHP_METHOD(Cyant_EventManager_SharedEventManager, clearListeners);
PHP_METHOD(Cyant_EventManager_SharedEventManager, getEvents);

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_attach, 0, 0, 3)
	ZEND_ARG_INFO(0, identifiers)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_attachaggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, aggregate)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_detach, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, listener)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_detachaggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, aggregate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_getlisteners, 0, 0, 2)
	ZEND_ARG_INFO(0, identifiers)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanager_getevents, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(cyant_eventmanager_sharedeventmanager_method_entry) {
	PHP_ME(Cyant_EventManager_SharedEventManager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Cyant_EventManager_SharedEventManager, attach, arginfo_cyant_eventmanager_sharedeventmanager_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_SharedEventManager, attachAggregate, arginfo_cyant_eventmanager_sharedeventmanager_attachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_SharedEventManager, detach, arginfo_cyant_eventmanager_sharedeventmanager_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_SharedEventManager, detachAggregate, arginfo_cyant_eventmanager_sharedeventmanager_detachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_SharedEventManager, getListeners, arginfo_cyant_eventmanager_sharedeventmanager_getlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_SharedEventManager, clearListeners, arginfo_cyant_eventmanager_sharedeventmanager_clearlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_SharedEventManager, getEvents, arginfo_cyant_eventmanager_sharedeventmanager_getevents, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
