namespace Zephir\EventManager\Exception;

class InvalidCallbackException extends Zephir\EventManager\Exception\DomainException
{
    public function __construct(string message)
    {
    }
}
