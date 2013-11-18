PHP_ARG_ENABLE(cyant, whether to enable cyant, [ --enable-cyant   Enable Cyant])

if test "$PHP_CYANT" = "yes"; then
	AC_DEFINE(HAVE_CYANT, 1, [Whether you have Cyant])
	cyant_sources="cyant.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/alternative/fcall.c kernel/file.c kernel/operators.c kernel/concat.c cyant/eventmanager/event.c cyant/eventmanager/eventinterface.c cyant/eventmanager/eventmanager.c cyant/eventmanager/eventmanagerinterface.c cyant/eventmanager/listeneraggregateinterface.c cyant/eventmanager/responsecollection.c cyant/eventmanager/sharedeventmanagerawareinterface.c"
	PHP_NEW_EXTENSION(cyant, $cyant_sources, $ext_shared)
fi
