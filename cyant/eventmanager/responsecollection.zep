/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Cyant\EventManager;

/**
 * Collection of signal handler return values
 *
 * We used to use a SplStack in Zend Framework 2, but using an array allows us some interesting
 * optimizations
 */
class ResponseCollection
{
    /**
     * @var array
     */
    protected responses;

    /**
     * @var bool
     */
    protected stopped = false;

    /**
     * @param array responses
     */
    public function __construct(responses = null)
    {
        if responses == null {
            let responses = [];
        }

        if !is_array(responses) {
            trigger_error("First argument must be an array", E_USER_ERROR);
        }

        let this->responses = responses;
    }

    /**
     * Did the last response provided trigger a short circuit of the stack?
     *
     * @return bool
     */
    public function stopped()
    {
        return this->stopped;
    }

    /**
     * Mark the collection as stopped (or its opposite)
     *
     * @param  bool flag
     * @return void
     */
    public function setStopped(boolean flag)
    {
        let this->stopped = flag;
    }

    /**
     * Convenient access to the first handler return value.
     *
     * @return mixed The first handler return value
     */
    public function first()
    {
        reset(this->responses);
        return current(this->responses);
    }

    /**
     * Convenient access to the last handler return value.
     *
     * If the collection is empty, returns null. Otherwise, returns value
     * returned by last handler.
     *
     * @return mixed The last handler return value
     */
    public function last()
    {
        var last;
        let last = end(this->responses);

        if last === false {
            return null;
        } else {
            return last;
        }
    }

    /**
     * Check if any of the responses match the given value.
     *
     * @param  mixed value The value to look for among responses
     * @return bool
     */
    public function contains(value)
    {
        return in_array(value, this->responses, true);
    }
}
