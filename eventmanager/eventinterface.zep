namespace Zephir\EventManager;

interface EventInterface
{
    public function getName();
    public function getTarget();
    public function getParams();
    public function getParam(param, defaultValue = null);
    public function setName(name);
    public function setTarget(target);
    public function setParams(params);
    public function setParam(param, value);
    public function stopPropagation(boolean flag = true);
    public function propagationIsStopped();
}
