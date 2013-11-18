/**
 * Cyant Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Cyant Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Cyant\EventManager;

/**
 * Interface to automate setter injection for a SharedEventManagerInterface instance
 */
interface SharedEventManagerAwareInterface
{
    /**
     * Inject a SharedEventManager instance
     *
     * @param  SharedEventManagerInterface sharedEventManager
     * @return SharedEventManagerAwareInterface
     */
    public function setSharedManager(<Cyant\EventManager\SharedEventManagerInterface> sharedEventManager);

    /**
     * Get shared collections container
     *
     * @return SharedEventManagerInterface
     */
    public function getSharedManager();
}
