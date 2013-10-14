namespace Zephir\EventManager;

interface ListenerAggregateInterface
{
    public function attach(<Zephir\EventManager\EventManagerInterface> events);
    public function detach(<Zephir\EventManager\EventManagerInterface> events);
}
