namespace Zephir\EventManager;

class ResponseCollection extends \SplStack
{
    protected stopped = false;

    public function stopped()
    {
        return this->stopped;
    }

    public function setStopped(boolean stopped)
    {
        let this->stopped = stopped;
    }

    public function first()
    {
        return parent::bottom();
    }

    public function last()
    {
        if count(this) == 0 {
            return null;
        }

        return parent::top();
    }

    public function contains(value)
    {
        var response;
        for response in this {
            if (response == value) {
                return true;
            }
        }

        return false;
    }
}
