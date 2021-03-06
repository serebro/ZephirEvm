namespace Zephir\EventManager;

interface SharedEventManagerAwareInterface
{
    /**
     * Inject a SharedEventManager instance
     *
     * @param  SharedEventManagerInterface $sharedEventManager
     * @return SharedEventManagerAwareInterface
     */
    public function setSharedManager(<Zephir\EventManager\SharedEventManagerInterface> sharedEventManager);

    /**
     * Get shared collections container
     *
     * @return SharedEventManagerInterface
     */
    public function getSharedManager();

    /**
     * Remove any shared collections
     *
     * @return void
     */
    public function unsetSharedManager();
}
