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
 *
 * Encapsulates the target context and parameters passed, and provides some
 * behavior for interacting with the event manager.
 */
class Event implements Cyant\EventManager\EventInterface
{
    /**
     * @var string|object The event target
     */
    protected target;

    /**
     * @var array The event parameters
     */
    protected params;

    /**
     * @var bool Whether or not to stop propagation
     */
    protected stopPropagation = false;

    /**
     * Constructor
     *
     * Accept a target and its parameters.
     *
     * @param  string|object     target
     * @param  array|Traversable params
     */
    public function __construct(target = null, params = null)
    {
        let params = [];

        this->setTarget(target);

        if (params !== null) {
            this->setParams(params);
        }
    }

    /**
     * {@inheritDoc}
     */
    public function setTarget(target)
    {
        let this->target = target;
    }

    /**
     * {@inheritDoc}
     *
     * This may be either an object, or the name of a static method.
     */
    public function getTarget()
    {
        return this->target;
    }

    /**
     * {@inheritDoc}
     */
    public function setParams(params)
    {
        if (params instanceof Traversable) {
            let params = iterator_to_array(params);
        }

        let this->params = params;
    }

    /**
     * {@inheritDoc}
     */
    public function setParam(name, value)
    {
        let this->params[name] = value;
    }

    /**
     * {@inheritDoc}
     */
    public function getParams()
    {
        return this->params;
    }

    /**
     * {@inheritDoc}
     */
    public function getParam(name, def = null)
    {
        if isset this->params[name] {
            return this->params[name];
        }

        return this->params[name];
    }

    /**
     * {@inheritDoc}
     */
    public function stopPropagation(boolean flag = true)
    {
        let this->stopPropagation = flag;
    }

    /**
     * {@inheritDoc}
     */
    public function isPropagationStopped()
    {
        return this->stopPropagation;
    }
}
