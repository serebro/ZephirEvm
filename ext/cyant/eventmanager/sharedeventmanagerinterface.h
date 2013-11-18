
extern zend_class_entry *cyant_eventmanager_sharedeventmanagerinterface_ce;

ZEPHIR_INIT_CLASS(Cyant_EventManager_SharedEventManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_attach, 0, 0, 3)
	ZEND_ARG_INFO(0, identifiers)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_attachaggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, aggregate)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_detach, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, listener)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_detachaggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, aggregate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_getlisteners, 0, 0, 2)
	ZEND_ARG_INFO(0, identifiers)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_sharedeventmanagerinterface_getevents, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(cyant_eventmanager_sharedeventmanagerinterface_method_entry) {
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, attach, arginfo_cyant_eventmanager_sharedeventmanagerinterface_attach)
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, attachAggregate, arginfo_cyant_eventmanager_sharedeventmanagerinterface_attachaggregate)
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, detach, arginfo_cyant_eventmanager_sharedeventmanagerinterface_detach)
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, detachAggregate, arginfo_cyant_eventmanager_sharedeventmanagerinterface_detachaggregate)
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, getListeners, arginfo_cyant_eventmanager_sharedeventmanagerinterface_getlisteners)
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, clearListeners, arginfo_cyant_eventmanager_sharedeventmanagerinterface_clearlisteners)
	PHP_ABSTRACT_ME(Cyant_EventManager_SharedEventManagerInterface, getEvents, arginfo_cyant_eventmanager_sharedeventmanagerinterface_getevents)
	PHP_FE_END
};
