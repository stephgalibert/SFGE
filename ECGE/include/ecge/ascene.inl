namespace ecge
{
    template<typename T, typename... Args>
    std::shared_ptr<T> AScene::instantiate(Args &&... args)
    {
        auto obj = std::make_shared<T>(std::forward<Args>(args)...);
        addGameObject(obj);
        return obj;
    }
}// namespace ecge