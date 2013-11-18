
extern zend_class_entry *cyant_eventmanager_eventinterface_ce;

ZEPHIR_INIT_CLASS(Cyant_EventManager_EventInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventinterface_settarget, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_eventinterface_stoppropagation, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(cyant_eventmanager_eventinterface_method_entry) {
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, setTarget, arginfo_cyant_eventmanager_eventinterface_settarget)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, getTarget, NULL)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, setParams, arginfo_cyant_eventmanager_eventinterface_setparams)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, setParam, arginfo_cyant_eventmanager_eventinterface_setparam)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, getParam, arginfo_cyant_eventmanager_eventinterface_getparam)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, stopPropagation, arginfo_cyant_eventmanager_eventinterface_stoppropagation)
	PHP_ABSTRACT_ME(Cyant_EventManager_EventInterface, isPropagationStopped, NULL)
	PHP_FE_END
};
