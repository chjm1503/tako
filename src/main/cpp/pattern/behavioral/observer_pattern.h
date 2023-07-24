#ifndef HZH_PATTERN_BEHAVIORAL_OBSERVER_PATTERN_H__
#define HZH_PATTERN_BEHAVIORAL_OBSERVER_PATTERN_H__

#include <cinttypes>

namespace hzh
{

    class ILastError
    {
    public:
        virtual ~ILastError() = default;

        virtual int32_t GetLastErrorCode() = 0;
        virtual const char const *GetLastError() = 0;
    };

    namespace pattern
    {
        namespace behavioral
        {
            class IObserver;
            class ISubject;

            class IObserver
            {
            public:
                virtual ~IObserver() = default;

                virtual void Update(void *msg, uint16_t msg_len) = 0;
            };

            class ISubject
            {
            public:
                virtual ~ISubject() = default;

                virtual void Attach(IObserver *observer) = 0;
                virtual void Detach(IObserver *observer) = 0;
                virtual void Notify() = 0;
            };

        } // namespace behavioral

        namespace demo
        {
            namespace behavioral
            {
                class SubjectDefault final : public hzh::pattern::behavioral::ISubject
                {
                public:
                    explicit SubjectDefault();
                    ~SubjectDefault() override;

                    void Attach(hzh::pattern::behavioral::IObserver *observer) override;
                    void Detach(hzh::pattern::behavioral::IObserver *observer) override;
                    void Notify() override;
                };

                class ObserverDefault final : public hzh::pattern::behavioral::IObserver
                {
                public:
                    explicit ObserverDefault();
                    ~ObserverDefault() override;

                    void Update(void *msg, uint16_t msg_len) override;
                };

                class ObserverAnother final : public hzh::pattern::behavioral::IObserver
                {
                public:
                    explicit ObserverAnother();
                    ~ObserverAnother() override;

                    void Update(void *msg, uint16_t msg_len) override;
                };

                void TestObserverPattern();
            } // namespace behavioral

        } // namespace demo

    } // namespace pattern

} // namespace hzh

#endif // HZH_PATTERN_BEHAVIORAL_OBSERVER_PATTERN_H__