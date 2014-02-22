
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "cyant.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *cyant_eventmanager_sharedeventmanagerawareinterface_ce;
zend_class_entry *cyant_eventmanager_eventinterface_ce;
zend_class_entry *cyant_eventmanager_eventmanagerinterface_ce;
zend_class_entry *cyant_eventmanager_listeneraggregateinterface_ce;
zend_class_entry *cyant_eventmanager_sharedeventmanagerinterface_ce;
zend_class_entry *cyant_eventmanager_sharedlisteneraggregateinterface_ce;
zend_class_entry *cyant_eventmanager_event_ce;
zend_class_entry *cyant_eventmanager_eventmanager_ce;
zend_class_entry *cyant_eventmanager_responsecollection_ce;
zend_class_entry *cyant_eventmanager_sharedeventmanager_ce;

ZEND_DECLARE_MODULE_GLOBALS(cyant)

static PHP_MINIT_FUNCTION(cyant)
{
#if PHP_VERSION_ID < 50500
	const char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		char *tmp = calloc(strlen(old_lc_all)+1, 1);
		memcpy(tmp, old_lc_all, strlen(old_lc_all));
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Cyant_EventManager_SharedEventManagerAwareInterface);
	ZEPHIR_INIT(Cyant_EventManager_EventInterface);
	ZEPHIR_INIT(Cyant_EventManager_EventManagerInterface);
	ZEPHIR_INIT(Cyant_EventManager_ListenerAggregateInterface);
	ZEPHIR_INIT(Cyant_EventManager_SharedEventManagerInterface);
	ZEPHIR_INIT(Cyant_EventManager_SharedListenerAggregateInterface);
	ZEPHIR_INIT(Cyant_EventManager_Event);
	ZEPHIR_INIT(Cyant_EventManager_EventManager);
	ZEPHIR_INIT(Cyant_EventManager_ResponseCollection);
	ZEPHIR_INIT(Cyant_EventManager_SharedEventManager);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(cyant)
{

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache options */
	zephir_globals->function_cache = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(cyant)
{

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//cyant_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(cyant)
{

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(cyant)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_CYANT_NAME, "enabled");
	php_info_print_table_row(2, "Version", PHP_CYANT_VERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(cyant)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(cyant_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(16, sizeof(zval*), 1);
	start->capacity        = 16;
	start->hash_addresses  = pecalloc(4, sizeof(zval*), 1);
	start->hash_capacity   = 4;

	cyant_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(cyant_globals->global_false);
	INIT_PZVAL(cyant_globals->global_false);
	ZVAL_FALSE(cyant_globals->global_false);
	Z_ADDREF_P(cyant_globals->global_false);

	ALLOC_PERMANENT_ZVAL(cyant_globals->global_true);
	INIT_PZVAL(cyant_globals->global_true);
	ZVAL_TRUE(cyant_globals->global_true);
	Z_ADDREF_P(cyant_globals->global_true);

	ALLOC_PERMANENT_ZVAL(cyant_globals->global_null);
	INIT_PZVAL(cyant_globals->global_null);
	ZVAL_NULL(cyant_globals->global_null);
	Z_ADDREF_P(cyant_globals->global_null);

}

static PHP_GSHUTDOWN_FUNCTION(cyant)
{
	assert(cyant_globals->start_memory != NULL);

	pefree(cyant_globals->start_memory->hash_addresses, 1);
	pefree(cyant_globals->start_memory->addresses, 1);
	pefree(cyant_globals->start_memory, 1);
	cyant_globals->start_memory = NULL;
}

zend_module_entry cyant_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_CYANT_EXTNAME,
	NULL,
	PHP_MINIT(cyant),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(cyant),
#else
	NULL,
#endif
	PHP_RINIT(cyant),
	PHP_RSHUTDOWN(cyant),
	PHP_MINFO(cyant),
	PHP_CYANT_VERSION,
	ZEND_MODULE_GLOBALS(cyant),
	PHP_GINIT(cyant),
	PHP_GSHUTDOWN(cyant),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_CYANT
ZEND_GET_MODULE(cyant)
#endif
