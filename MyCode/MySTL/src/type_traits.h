#ifndef MY_TYPE_TRAITS_H
#define MY_TYPE_TRAITS_H
#include <c++/type_traits>

namespace mystl
{

    template<bool value,class T>
    struct enable_if{};


    template<class T>
    struct enable_if<true,T>
    {
        typedef T   value_type;
    };


    template<class T,T v>
    struct m_intergral_constant
    {
        static constexpr T value = v;
    };

    template<bool b>
    using m_bool_constant = m_intergral_constant<bool,b>;

    typedef m_bool_constant<true> m_true_type;
    typedef m_bool_constant<false> m_false_type;


    template<class T1,class T2>
    struct pair;

    template<class T>
    struct is_pair:m_false_type{};

    template<class T1,class T2>
    struct is_pair:m_true_type{};

}
#endif
