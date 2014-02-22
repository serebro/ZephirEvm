
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_CYANT_H
#define PHP_CYANT_H 1

#include "kernel/globals.h"

#define PHP_CYANT_NAME    "cyant"
#define PHP_CYANT_VERSION "0.0.1"
#define PHP_CYANT_EXTNAME "cyant"



ZEND_BEGIN_MODULE_GLOBALS(cyant)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(cyant)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(cyant)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(cyant_globals_id, zend_cyant_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (cyant_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_cyant_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(cyant_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(cyant_globals)
#endif

#define zephir_globals cyant_globals
#define zend_zephir_globals zend_cyant_globals

extern zend_module_entry cyant_module_entry;
#define phpext_cyant_ptr &cyant_module_entry

#endif
