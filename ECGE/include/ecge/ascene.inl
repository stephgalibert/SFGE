namespace ecge
{
    template<typename T, typename... Args>
    std::shared_ptr<T> AScene::Instantiate(Args &&... args)
    {
        auto obj = std::make_shared<T>(std::forward<Args>(args)...);
        addGameObject(obj);
        return obj;
    }
}// namespace ecge