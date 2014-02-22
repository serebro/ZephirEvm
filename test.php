<?php
/**
 * @author Antoine Hedgcock <antoine@pmg.se>
 *
 * @copyright PMG Media Group AB
 */

function emptyFunc($event)
{
    return 'test';
}

$closure = function() {};

$numberOfListeners = 100;
$numberOfTriggers  = 1000;
$totalTimeStart    = microtime(true);;

$eventManager  = new \Cyant\EventManager\EventManager(array('myid'));

echo "Attach {$numberOfListeners} listeners:        ";
$memStart  = memory_get_usage();
$timeStart = microtime(true);
for ($i = 0; $i < $numberOfListeners; ++$i) {
    $eventManager->attach('event', $closure, $i);
}
$timeEnd = microtime(true);
$memEnd  = memory_get_usage(true);
printf("time=%f, mem=%d\n", $timeEnd - $timeStart, $memEnd - $memStart);


echo "Triggers {$numberOfTriggers} events:        ";
$memStart  = memory_get_usage();
$timeStart = microtime(true);
for ($i = 0; $i < $numberOfListeners; ++$i) {
    $eventManager->trigger('event');
}
$timeEnd = microtime(true);
$memEnd  = memory_get_usage(true);

printf("time=%f, mem=%d\n", $timeEnd - $timeStart, $memEnd - $memStart);


