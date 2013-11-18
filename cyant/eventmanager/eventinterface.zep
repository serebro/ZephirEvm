/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Cyant\EventManager;

/**
 * Representation of an event
 */
interface EventInterface
{
    /**
     * Set the event target/context
     *
     * @param  null|string|object target
     * @return void
     */
    public function setTarget(target);

    /**
     * Get target/context from which event was triggered
     *
     * @return null|string|object
     */
    public function getTarget();

    /**
     * Set event parameters (overwrite parameters)
     *
     * @param  array|Traversable params
     * @return void
     */
    public function setParams(params);

    /**
     * Set a single parameter by key
     *
     * @param  string name
     * @param  mixed  value
     * @return void
     */
    public function setParam(name, value);

    /**
     * Get parameters passed to the event
     *
     * @return array
     */
    public function getParams();

    /**
     * Get a single parameter by name
     *
     * @param  string name
     * @param  mixed  default Default value to return if parameter does not exist
     * @return mixed
     */
    public function getParam(name, def = null);

    /**
     * Indicate whether or not the parent EventManagerInterface should stop propagating events
     *
     * @param  bool flag
     * @return void
     */
    public function stopPropagation(boolean flag = true);

    /**
     * Has this event indicated event propagation should stop?
     *
     * @return bool
     */
    public function isPropagationStopped();
}
