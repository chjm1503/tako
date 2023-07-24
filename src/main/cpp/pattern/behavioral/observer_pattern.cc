#include "observer_pattern.h"

hzh::pattern::demo::behavioral::SubjectDefault::SubjectDefault()
{
}

hzh::pattern::demo::behavioral::SubjectDefault::~SubjectDefault()
{
}

void hzh::pattern::demo::behavioral::SubjectDefault::Attach(hzh::pattern::behavioral::IObserver *observer)
{
}

void hzh::pattern::demo::behavioral::SubjectDefault::Detach(hzh::pattern::behavioral::IObserver *observer)
{
}

void hzh::pattern::demo::behavioral::SubjectDefault::Notify()
{
}

hzh::pattern::demo::behavioral::ObserverDefault::ObserverDefault()
{
}

hzh::pattern::demo::behavioral::ObserverDefault::~ObserverDefault()
{
}

void hzh::pattern::demo::behavioral::ObserverDefault::Update(void *msg, uint16_t msg_len)
{
}

hzh::pattern::demo::behavioral::ObserverAnother::ObserverAnother()
{
}

hzh::pattern::demo::behavioral::ObserverAnother::~ObserverAnother()
{
}

void hzh::pattern::demo::behavioral::ObserverAnother::Update(void *msg, uint16_t msg_len)
{
}

void hzh::pattern::demo::behavioral::TestObserverPattern()
{
}
