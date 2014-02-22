
extern zend_class_entry *cyant_eventmanager_responsecollection_ce;

ZEPHIR_INIT_CLASS(Cyant_EventManager_ResponseCollection);

PHP_METHOD(Cyant_EventManager_ResponseCollection, __construct);
PHP_METHOD(Cyant_EventManager_ResponseCollection, stopped);
PHP_METHOD(Cyant_EventManager_ResponseCollection, setStopped);
PHP_METHOD(Cyant_EventManager_ResponseCollection, first);
PHP_METHOD(Cyant_EventManager_ResponseCollection, last);
PHP_METHOD(Cyant_EventManager_ResponseCollection, contains);

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_responsecollection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, responses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_responsecollection_setstopped, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cyant_eventmanager_responsecollection_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(cyant_eventmanager_responsecollection_method_entry) {
	PHP_ME(Cyant_EventManager_ResponseCollection, __construct, arginfo_cyant_eventmanager_responsecollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Cyant_EventManager_ResponseCollection, stopped, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_ResponseCollection, setStopped, arginfo_cyant_eventmanager_responsecollection_setstopped, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_ResponseCollection, first, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_ResponseCollection, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Cyant_EventManager_ResponseCollection, contains, arginfo_cyant_eventmanager_responsecollection_contains, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
