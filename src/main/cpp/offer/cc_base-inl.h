#ifndef HZH_OFFER_CC_BASE_H__
#define HZH_OFFER_CC_BASE_H__

#include <iostream>

namespace hzh
{
    namespace offer
    {
        using namespace std;
#if defined(WIN32)
#define ENDLINE "MSVC\n";
#elif defined(__linux__)
#define ENDLINE "g++\n";
#elif defined(__APPLE__)
#define ENDLINE "clang++\n";
#elif defined(__ANDROID__)
#define ENDLINE "ndk\n";
#else
#define ENDLINE "\n";
#endif

#define PRINT cout << /*__FUNCITON__*/ " "

        inline void TestSizeofStruct()
        {
            // Q
            // 定义一个空类型，里面没有任何变量和成员函数。对该函数求sizeof，得到的结果是多少
            typedef struct empty_s
            {

            } Empty;
            const auto empty_size = sizeof(Empty);
            PRINT << "空结构体 sizeof值为" << empty_size << ENDLINE;

            typedef struct contract_s
            {
                contract_s() = default;
                ~contract_s() = default;
            } Contract;
            const auto contract_size = sizeof(Contract);
            PRINT << "含有一个构造函数和析构函数的结构体 sizeof值为" << contract_size << ENDLINE;

            typedef struct virtual_contract_s
            {
                virtual_contract_s() = default;
                virtual ~virtual_contract_s() = default;
            } VirtualContract;
            const auto virtual_contract_size = sizeof(VirtualContract);
            PRINT << "含有一个构造函数和虚析构函数的结构体 sizeof值为" << virtual_contract_size << ENDLINE;

            typedef struct func_wrapper_s
            {
                func_wrapper_s() = default;
                virtual ~func_wrapper_s() = default;

                void print() {}
            } FuncWrapper;
            const auto func_wrapper_size = sizeof(FuncWrapper);
            PRINT << "带有成员函数的结构体 sizeof值为" << func_wrapper_size << ENDLINE;
        }

        void TestClass()
        {
            class A
            {
                int value;
                float preferential{1.f};

            public:
                A(int n) { value = n; }
                // compiler error
                // A(A other) { value = other.value; }
                A(const A &other) { value = other.value; }
                void Print() { cout << value << endl; }
                // 为什么不直接暴露属性值为public
                // 模拟支付的优惠场景
                void SetPreferential(float preferential)
                {
                    if (preferential < 0.f)
                        return;
                    this->preferential = preferential;
                }
                void SetValue(const int &n) { this->value = static_cast<int>(n / preferential); }
            };

            A a = 10;
            A b = a;
            a.SetPreferential(0.5);
            a.SetValue(4);
            b.Print();
            A(a).Print();
        }

        void TestStringClass()
        {
            class CMyString
            {
            public:
                CMyString(char *data = nullptr)
                {
                    if (data == nullptr)
                    {
                        m_data = new char[1];
                        m_data[0] = '\0';
                    }
                    else
                    {
                        const auto size = strlen(data);
                        m_data = new char[size + 1]();
#ifdef WIN32
                        strcpy_s(m_data, size, data);
#else
                        strcpy(m_data, data);
#endif
                    }
                }
                CMyString(const CMyString &str)
                {
                    const auto length = strlen(str.m_data);
                    m_data = new char[length + 1];
#ifdef WIN32
                    strcpy_s(m_data, length, str.m_data);
#else
                    strcpy(m_data, str.m_data);
#endif
                }
                ~CMyString()
                {
                    if (m_data != nullptr)
                    {
                        cout << "point address: " << static_cast<const void *>(m_data) << endl;
                        delete[] m_data;
                        m_data = nullptr;
                    }
                }

                CMyString &operator=(const CMyString &str)
                {
                    // copy and swap
                    if (this != &str)
                    {
                        CMyString tmp(str);

                        char *p_tmp = tmp.m_data;
                        tmp.m_data = m_data;
                        m_data = p_tmp;
                    }

                    return *this;
                }

                void Print() const
                {
                    cout << m_data << endl;
                }

            private:
                char *m_data;
            };

            CMyString a = "abc";
            a.Print();
            a = CMyString("123");
            a.Print();
        }

    } // namespace offer
} // namespace hzh

#endif // HZH_OFFER_CC_BASE_H__