/*
 * Portions Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 *
 * Copyright (c) 1999
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

// WARNING: This is an internal header file, included by other C++
// standard library headers.  You should not attempt to use this header
// file directly.


#ifndef _STLP_INTERNAL_MESSAGES_H
#define _STLP_INTERNAL_MESSAGES_H

#ifndef _STLP_IOS_BASE_H
#  include <stl/_ios_base.h>
#endif

#ifndef _STLP_C_LOCALE_H
#  include <stl/c_locale.h>
#endif

#ifndef _STLP_INTERNAL_STRING_H
#  include <stl/_string.h>
#endif

_STLP_BEGIN_NAMESPACE

// messages facets

class messages_base {
  public:
    typedef int catalog;
};

template <class _CharT> class messages {};

_STLP_MOVE_TO_PRIV_NAMESPACE
class _Messages;
_STLP_MOVE_TO_STD_NAMESPACE

_STLP_TEMPLATE_NULL
class _STLP_CLASS_DECLSPEC messages<char> : public locale::facet, public messages_base {
  friend class _Locale_impl;
public:
  typedef messages_base::catalog catalog;
  typedef char                   char_type;
  typedef string    string_type;

  _STLP_DECLSPEC explicit messages(size_t __refs = 0);

  catalog open(const string& __fn, const locale& __loc) const
  { return do_open(__fn, __loc); }
  string_type get(catalog __c, int __set, int __msgid,
                  const string_type& __dfault) const
  { return do_get(__c, __set, __msgid, __dfault); }
  inline void close(catalog __c) const
  { do_close(__c); }

#if defined(__SYMBIAN32__WSD__) 
  static _STLP_STATIC_MEMBER_DECLSPEC locale::id& GetFacetLocaleId();
#elif defined (__SYMBIAN32__NO_STATIC_IMPORTS__)    
  static _STLP_STATIC_MEMBER_DECLSPEC locale::id& GetFacetLocaleId();
  static locale::id id;           
#else
  // NOTE: Symbian doesn't support exporting static data.  
  // Users of this class should use GetFacetLocaleId() to access the data member id  
  static _STLP_STATIC_MEMBER_DECLSPEC locale::id id;
#endif

private:
  _STLP_DECLSPEC messages(_STLP_PRIV _Messages*);

protected:
  _STLP_DECLSPEC messages(size_t, _Locale_messages*);
  _STLP_DECLSPEC ~messages();


  _STLP_DECLSPEC virtual catalog     do_open(const string& __fn, const locale& __loc) const;
  _STLP_DECLSPEC virtual string_type do_get(catalog __c, int __set, int __msgid,
                             const string_type& __dfault) const;
  _STLP_DECLSPEC virtual void        do_close(catalog __c) const;

  void _M_initialize(const char* __name);

private:
  _STLP_PRIV _Messages* _M_impl;
};

#if !defined (_STLP_NO_WCHAR_T)

_STLP_TEMPLATE_NULL
class _STLP_CLASS_DECLSPEC messages<wchar_t> : public locale::facet, public messages_base {
  friend class _Locale_impl;
public:
  typedef messages_base::catalog catalog;
  typedef wchar_t                char_type;
  typedef wstring  string_type;

  explicit messages(size_t __refs = 0);

  inline catalog open(const string& __fn, const locale& __loc) const
    { return do_open(__fn, __loc); }
  inline string_type get(catalog __c, int __set, int __msgid,
                         const string_type& __dfault) const
    { return do_get(__c, __set, __msgid, __dfault); }
  inline void close(catalog __c) const
    { do_close(__c); }

#if defined(__SYMBIAN32__WSD__) 
  static _STLP_STATIC_MEMBER_DECLSPEC locale::id& GetFacetLocaleId();
#elif defined (__SYMBIAN32__NO_STATIC_IMPORTS__)    
  static _STLP_STATIC_MEMBER_DECLSPEC locale::id& GetFacetLocaleId();
  static locale::id id;        
#else
  // NOTE: Symbian doesn't support exporting static data.  
  // Users of this class should use GetFacetLocaleId() to access the data member id  
  static _STLP_STATIC_MEMBER_DECLSPEC locale::id id;
#endif

private:
  _STLP_DECLSPEC messages(_STLP_PRIV _Messages*);

protected:
  _STLP_DECLSPEC messages(size_t, _Locale_messages*);
  _STLP_DECLSPEC ~messages();

  _STLP_DECLSPEC virtual catalog     do_open(const string& __fn, const locale& __loc) const;
  _STLP_DECLSPEC virtual string_type do_get(catalog __c, int __set, int __msgid,
                             const string_type& __dfault) const;
  _STLP_DECLSPEC virtual void        do_close(catalog __c) const;

  void _M_initialize(const char* __name);

private:
  _STLP_PRIV _Messages* _M_impl;
};

#endif

template <class _CharT> class messages_byname {};

_STLP_TEMPLATE_NULL
class _STLP_CLASS_DECLSPEC messages_byname<char> : public messages<char> {
public:
  typedef messages_base::catalog catalog;
  typedef string     string_type;

  _STLP_DECLSPEC explicit messages_byname(const char* __name, size_t __refs = 0, _Locale_name_hint* __hint = 0);

protected:
  ~messages_byname();

private:
  typedef messages_byname<char> _Self;
  //explicitely defined as private to avoid warnings:
  messages_byname(_Self const&);
  _Self& operator = (_Self const&);
};

#if !defined (_STLP_NO_WCHAR_T)
_STLP_TEMPLATE_NULL
class _STLP_CLASS_DECLSPEC messages_byname<wchar_t> : public messages<wchar_t> {
public:
  typedef messages_base::catalog catalog;
  typedef wstring                string_type;

  _STLP_DECLSPEC explicit messages_byname(const char* __name, size_t __refs = 0, _Locale_name_hint* __hint = 0);

protected:
  ~messages_byname();

private:
  typedef messages_byname<wchar_t> _Self;
  //explicitely defined as private to avoid warnings:
  messages_byname(_Self const&);
  _Self& operator = (_Self const&);
};
#endif /* WCHAR_T */

_STLP_END_NAMESPACE

#endif /* _STLP_INTERNAL_MESSAGES_H */

// Local Variables:
// mode:C++
// End:

