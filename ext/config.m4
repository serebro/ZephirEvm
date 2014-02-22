PHP_ARG_ENABLE(cyant, whether to enable cyant, [ --enable-cyant   Enable Cyant])

if test "$PHP_CYANT" = "yes"; then
	AC_DEFINE(HAVE_CYANT, 1, [Whether you have Cyant])
	cyant_sources="cyant.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/alternative/fcall.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c cyant/eventmanager/event.c cyant/eventmanager/eventinterface.c cyant/eventmanager/eventmanager.c cyant/eventmanager/eventmanagerinterface.c cyant/eventmanager/listeneraggregateinterface.c cyant/eventmanager/responsecollection.c cyant/eventmanager/sharedeventmanager.c cyant/eventmanager/sharedeventmanagerawareinterface.c cyant/eventmanager/sharedeventmanagerinterface.c cyant/eventmanager/sharedlisteneraggregateinterface.c "
	PHP_NEW_EXTENSION(cyant, $cyant_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([cyant], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([cyant], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS
fi
