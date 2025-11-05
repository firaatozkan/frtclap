#pragma once

#include <tuple>

#include "frtclap/size_t_.hpp"

namespace frtclap::detail
{
    template <class... Args>
    [[nodiscard]] constexpr auto make_tuple_of_references(Args&&... args) noexcept
    {
        return std::tuple<Args&...>{args...};
    }

    template <typename T, typename Arg>
    [[nodiscard]] constexpr decltype(auto) add_cv_like(Arg& arg) noexcept
    {
        if constexpr (std::is_const<T>::value && std::is_volatile<T>::value)
            return const_cast<const volatile Arg &>(arg);

        else if constexpr (std::is_const<T>::value)
            return const_cast<const Arg &>(arg);

        else if constexpr (std::is_volatile<T>::value)
            return const_cast<volatile Arg &>(arg);

        else
            return const_cast<Arg &>(arg);
    }

    template <typename T, typename Sb, typename Arg>
    [[nodiscard]] constexpr decltype(auto) workaround_cast(Arg& arg) noexcept
    {
        using output_arg_t = std::conditional_t<!std::is_reference<Sb>(), decltype(detail::add_cv_like<T>(arg)), Sb>;
        return const_cast<output_arg_t>(arg);
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T &, size_t_<0>) noexcept
    {
        return std::tuple<>{};
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<1>, std::enable_if_t<std::is_class<std::remove_cv_t<T>>::value>* = nullptr) noexcept
    {
        auto& [a] = const_cast<std::remove_cv_t<T>&>(val);
        return make_tuple_of_references(workaround_cast<T, decltype(a)>(a));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<1>, std::enable_if_t<!std::is_class<std::remove_cv_t<T>>::value>* = nullptr) noexcept
    {
        return make_tuple_of_references(val);
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<2>) noexcept
    {
        auto& [a, b] = const_cast<std::remove_cv_t<T>&>(val);
        return make_tuple_of_references(workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<3>) noexcept
    {
        auto& [a, b, c] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<4>) noexcept
    {
        auto& [a, b, c, d] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<5>) noexcept
    {
        auto& [a, b, c, d, e] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<6>) noexcept
    {
        auto& [a, b, c, d, e, f] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<7>) noexcept
    {
        auto& [a, b, c, d, e, f, g] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<8>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<9>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<10>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<11>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<12>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<13>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<14>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<15>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<16>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<17>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<18>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<19>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<20>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<21>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<22>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<23>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<24>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<25>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<26>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<27>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<28>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<29>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<30>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<31>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<32>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<33>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<34>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<35>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<36>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<37>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<38>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<39>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<40>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<41>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<42>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<43>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<44>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<45>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<46>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<47>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<48>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<49>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<50>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<51>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<52>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<53>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<54>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<55>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<56>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<57>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<58>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<59>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<60>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<61>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<62>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<63>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<64>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<65>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<66>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<67>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<68>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<69>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<70>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<71>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<72>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<73>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<74>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<75>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<76>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<77>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<78>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<79>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<80>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<81>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<82>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<83>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<84>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<85>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<86>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<87>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<88>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<89>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<90>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<91>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<92>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<93>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<94>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<95>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<96>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<97>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<98>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<99>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<100>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<101>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<102>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<103>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<104>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<105>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<106>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<107>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<108>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<109>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<110>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<111>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<112>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<113>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<114>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<115>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<116>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<117>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<118>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<119>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<120>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<121>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<122>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<123>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<124>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<125>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<126>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<127>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<128>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<129>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<130>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<131>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<132>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<133>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<134>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<135>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<136>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<137>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<138>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<139>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<140>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<141>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<142>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<143>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<144>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<145>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<146>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<147>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<148>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<149>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<150>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<151>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<152>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<153>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<154>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<155>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<156>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<157>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<158>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<159>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<160>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<161>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<162>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<163>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<164>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<165>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<166>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<167>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<168>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<169>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<170>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<171>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<172>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<173>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<174>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<175>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<176>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<177>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<178>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<179>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<180>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<181>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<182>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<183>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<184>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<185>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<186>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<187>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<188>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<189>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<190>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<191>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<192>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<193>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<194>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<195>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df, dg] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df), workaround_cast<T, decltype(dg)>(dg));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<196>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df, dg, dh] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df), workaround_cast<T, decltype(dg)>(dg),
            workaround_cast<T, decltype(dh)>(dh));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<197>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df, dg, dh, dj] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df), workaround_cast<T, decltype(dg)>(dg),
            workaround_cast<T, decltype(dh)>(dh), workaround_cast<T, decltype(dj)>(dj));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<198>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df, dg, dh, dj, dk] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df), workaround_cast<T, decltype(dg)>(dg),
            workaround_cast<T, decltype(dh)>(dh), workaround_cast<T, decltype(dj)>(dj), workaround_cast<T, decltype(dk)>(dk));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<199>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df, dg, dh, dj, dk, dl] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df), workaround_cast<T, decltype(dg)>(dg),
            workaround_cast<T, decltype(dh)>(dh), workaround_cast<T, decltype(dj)>(dj), workaround_cast<T, decltype(dk)>(dk),
            workaround_cast<T, decltype(dl)>(dl));
    }

    template <class T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val, size_t_<200>) noexcept
    {
        auto& [a, b, c, d, e, f, g, h, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, J, K, L, M, N, P, Q, R, S, U, V, W, X, Y, Z,
               aa, ab, ac, ad, ae, af, ag, ah, aj, ak, al, am, an, ap, aq, ar, as, at, au, av, aw, ax, ay, az, aA, aB, aC, aD, aE, aF, aG, aH, aJ, aK, aL, aM, aN, aP, aQ, aR, aS, aU, aV, aW, aX, aY, aZ,
               ba, bb, bc, bd, be, bf, bg, bh, bj, bk, bl, bm, bn, bp, bq, br, bs, bt, bu, bv, bw, bx, by, bz, bA, bB, bC, bD, bE, bF, bG, bH, bJ, bK, bL, bM, bN, bP, bQ, bR, bS, bU, bV, bW, bX, bY, bZ,
               ca, cb, cc, cd, ce, cf, cg, ch, cj, ck, cl, cm, cn, cp, cq, cr, cs, ct, cu, cv, cw, cx, cy, cz, cA, cB, cC, cD, cE, cF, cG, cH, cJ, cK, cL, cM, cN, cP, cQ, cR, cS, cU, cV, cW, cX, cY, cZ,
               da, db, dc, dd, de, df, dg, dh, dj, dk, dl, dm] = const_cast<std::remove_cv_t<T>&>(val);

        return make_tuple_of_references(
            workaround_cast<T, decltype(a)>(a), workaround_cast<T, decltype(b)>(b), workaround_cast<T, decltype(c)>(c),
            workaround_cast<T, decltype(d)>(d), workaround_cast<T, decltype(e)>(e), workaround_cast<T, decltype(f)>(f),
            workaround_cast<T, decltype(g)>(g), workaround_cast<T, decltype(h)>(h), workaround_cast<T, decltype(j)>(j),
            workaround_cast<T, decltype(k)>(k), workaround_cast<T, decltype(l)>(l), workaround_cast<T, decltype(m)>(m),
            workaround_cast<T, decltype(n)>(n), workaround_cast<T, decltype(p)>(p), workaround_cast<T, decltype(q)>(q),
            workaround_cast<T, decltype(r)>(r), workaround_cast<T, decltype(s)>(s), workaround_cast<T, decltype(t)>(t),
            workaround_cast<T, decltype(u)>(u), workaround_cast<T, decltype(v)>(v), workaround_cast<T, decltype(w)>(w),
            workaround_cast<T, decltype(x)>(x), workaround_cast<T, decltype(y)>(y), workaround_cast<T, decltype(z)>(z),
            workaround_cast<T, decltype(A)>(A), workaround_cast<T, decltype(B)>(B), workaround_cast<T, decltype(C)>(C),
            workaround_cast<T, decltype(D)>(D), workaround_cast<T, decltype(E)>(E), workaround_cast<T, decltype(F)>(F),
            workaround_cast<T, decltype(G)>(G), workaround_cast<T, decltype(H)>(H), workaround_cast<T, decltype(J)>(J),
            workaround_cast<T, decltype(K)>(K), workaround_cast<T, decltype(L)>(L), workaround_cast<T, decltype(M)>(M),
            workaround_cast<T, decltype(N)>(N), workaround_cast<T, decltype(P)>(P), workaround_cast<T, decltype(Q)>(Q),
            workaround_cast<T, decltype(R)>(R), workaround_cast<T, decltype(S)>(S), workaround_cast<T, decltype(U)>(U),
            workaround_cast<T, decltype(V)>(V), workaround_cast<T, decltype(W)>(W), workaround_cast<T, decltype(X)>(X),
            workaround_cast<T, decltype(Y)>(Y), workaround_cast<T, decltype(Z)>(Z), workaround_cast<T, decltype(aa)>(aa),
            workaround_cast<T, decltype(ab)>(ab), workaround_cast<T, decltype(ac)>(ac), workaround_cast<T, decltype(ad)>(ad),
            workaround_cast<T, decltype(ae)>(ae), workaround_cast<T, decltype(af)>(af), workaround_cast<T, decltype(ag)>(ag),
            workaround_cast<T, decltype(ah)>(ah), workaround_cast<T, decltype(aj)>(aj), workaround_cast<T, decltype(ak)>(ak),
            workaround_cast<T, decltype(al)>(al), workaround_cast<T, decltype(am)>(am), workaround_cast<T, decltype(an)>(an),
            workaround_cast<T, decltype(ap)>(ap), workaround_cast<T, decltype(aq)>(aq), workaround_cast<T, decltype(ar)>(ar),
            workaround_cast<T, decltype(as)>(as), workaround_cast<T, decltype(at)>(at), workaround_cast<T, decltype(au)>(au),
            workaround_cast<T, decltype(av)>(av), workaround_cast<T, decltype(aw)>(aw), workaround_cast<T, decltype(ax)>(ax),
            workaround_cast<T, decltype(ay)>(ay), workaround_cast<T, decltype(az)>(az), workaround_cast<T, decltype(aA)>(aA),
            workaround_cast<T, decltype(aB)>(aB), workaround_cast<T, decltype(aC)>(aC), workaround_cast<T, decltype(aD)>(aD),
            workaround_cast<T, decltype(aE)>(aE), workaround_cast<T, decltype(aF)>(aF), workaround_cast<T, decltype(aG)>(aG),
            workaround_cast<T, decltype(aH)>(aH), workaround_cast<T, decltype(aJ)>(aJ), workaround_cast<T, decltype(aK)>(aK),
            workaround_cast<T, decltype(aL)>(aL), workaround_cast<T, decltype(aM)>(aM), workaround_cast<T, decltype(aN)>(aN),
            workaround_cast<T, decltype(aP)>(aP), workaround_cast<T, decltype(aQ)>(aQ), workaround_cast<T, decltype(aR)>(aR),
            workaround_cast<T, decltype(aS)>(aS), workaround_cast<T, decltype(aU)>(aU), workaround_cast<T, decltype(aV)>(aV),
            workaround_cast<T, decltype(aW)>(aW), workaround_cast<T, decltype(aX)>(aX), workaround_cast<T, decltype(aY)>(aY),
            workaround_cast<T, decltype(aZ)>(aZ), workaround_cast<T, decltype(ba)>(ba), workaround_cast<T, decltype(bb)>(bb),
            workaround_cast<T, decltype(bc)>(bc), workaround_cast<T, decltype(bd)>(bd), workaround_cast<T, decltype(be)>(be),
            workaround_cast<T, decltype(bf)>(bf), workaround_cast<T, decltype(bg)>(bg), workaround_cast<T, decltype(bh)>(bh),
            workaround_cast<T, decltype(bj)>(bj), workaround_cast<T, decltype(bk)>(bk), workaround_cast<T, decltype(bl)>(bl),
            workaround_cast<T, decltype(bm)>(bm), workaround_cast<T, decltype(bn)>(bn), workaround_cast<T, decltype(bp)>(bp),
            workaround_cast<T, decltype(bq)>(bq), workaround_cast<T, decltype(br)>(br), workaround_cast<T, decltype(bs)>(bs),
            workaround_cast<T, decltype(bt)>(bt), workaround_cast<T, decltype(bu)>(bu), workaround_cast<T, decltype(bv)>(bv),
            workaround_cast<T, decltype(bw)>(bw), workaround_cast<T, decltype(bx)>(bx), workaround_cast<T, decltype(by)>(by),
            workaround_cast<T, decltype(bz)>(bz), workaround_cast<T, decltype(bA)>(bA), workaround_cast<T, decltype(bB)>(bB),
            workaround_cast<T, decltype(bC)>(bC), workaround_cast<T, decltype(bD)>(bD), workaround_cast<T, decltype(bE)>(bE),
            workaround_cast<T, decltype(bF)>(bF), workaround_cast<T, decltype(bG)>(bG), workaround_cast<T, decltype(bH)>(bH),
            workaround_cast<T, decltype(bJ)>(bJ), workaround_cast<T, decltype(bK)>(bK), workaround_cast<T, decltype(bL)>(bL),
            workaround_cast<T, decltype(bM)>(bM), workaround_cast<T, decltype(bN)>(bN), workaround_cast<T, decltype(bP)>(bP),
            workaround_cast<T, decltype(bQ)>(bQ), workaround_cast<T, decltype(bR)>(bR), workaround_cast<T, decltype(bS)>(bS),
            workaround_cast<T, decltype(bU)>(bU), workaround_cast<T, decltype(bV)>(bV), workaround_cast<T, decltype(bW)>(bW),
            workaround_cast<T, decltype(bX)>(bX), workaround_cast<T, decltype(bY)>(bY), workaround_cast<T, decltype(bZ)>(bZ),
            workaround_cast<T, decltype(ca)>(ca), workaround_cast<T, decltype(cb)>(cb), workaround_cast<T, decltype(cc)>(cc),
            workaround_cast<T, decltype(cd)>(cd), workaround_cast<T, decltype(ce)>(ce), workaround_cast<T, decltype(cf)>(cf),
            workaround_cast<T, decltype(cg)>(cg), workaround_cast<T, decltype(ch)>(ch), workaround_cast<T, decltype(cj)>(cj),
            workaround_cast<T, decltype(ck)>(ck), workaround_cast<T, decltype(cl)>(cl), workaround_cast<T, decltype(cm)>(cm),
            workaround_cast<T, decltype(cn)>(cn), workaround_cast<T, decltype(cp)>(cp), workaround_cast<T, decltype(cq)>(cq),
            workaround_cast<T, decltype(cr)>(cr), workaround_cast<T, decltype(cs)>(cs), workaround_cast<T, decltype(ct)>(ct),
            workaround_cast<T, decltype(cu)>(cu), workaround_cast<T, decltype(cv)>(cv), workaround_cast<T, decltype(cw)>(cw),
            workaround_cast<T, decltype(cx)>(cx), workaround_cast<T, decltype(cy)>(cy), workaround_cast<T, decltype(cz)>(cz),
            workaround_cast<T, decltype(cA)>(cA), workaround_cast<T, decltype(cB)>(cB), workaround_cast<T, decltype(cC)>(cC),
            workaround_cast<T, decltype(cD)>(cD), workaround_cast<T, decltype(cE)>(cE), workaround_cast<T, decltype(cF)>(cF),
            workaround_cast<T, decltype(cG)>(cG), workaround_cast<T, decltype(cH)>(cH), workaround_cast<T, decltype(cJ)>(cJ),
            workaround_cast<T, decltype(cK)>(cK), workaround_cast<T, decltype(cL)>(cL), workaround_cast<T, decltype(cM)>(cM),
            workaround_cast<T, decltype(cN)>(cN), workaround_cast<T, decltype(cP)>(cP), workaround_cast<T, decltype(cQ)>(cQ),
            workaround_cast<T, decltype(cR)>(cR), workaround_cast<T, decltype(cS)>(cS), workaround_cast<T, decltype(cU)>(cU),
            workaround_cast<T, decltype(cV)>(cV), workaround_cast<T, decltype(cW)>(cW), workaround_cast<T, decltype(cX)>(cX),
            workaround_cast<T, decltype(cY)>(cY), workaround_cast<T, decltype(cZ)>(cZ), workaround_cast<T, decltype(da)>(da),
            workaround_cast<T, decltype(db)>(db), workaround_cast<T, decltype(dc)>(dc), workaround_cast<T, decltype(dd)>(dd),
            workaround_cast<T, decltype(de)>(de), workaround_cast<T, decltype(df)>(df), workaround_cast<T, decltype(dg)>(dg),
            workaround_cast<T, decltype(dh)>(dh), workaround_cast<T, decltype(dj)>(dj), workaround_cast<T, decltype(dk)>(dk),
            workaround_cast<T, decltype(dl)>(dl), workaround_cast<T, decltype(dm)>(dm));
    }

    template <class T, std::size_t I>
    constexpr void tie_as_tuple(T &, size_t_<I>) noexcept
    {
        static_assert(sizeof(T) && false);
    }

} // namespace frtclap::detail
