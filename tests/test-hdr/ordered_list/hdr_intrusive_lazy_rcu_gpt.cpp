/*
    This file is a part of libcds - Concurrent Data Structures library
    See http://libcds.sourceforge.net/

    (C) Copyright Maxim Khiszinsky (libcds.sf.com) 2006-2013
    Distributed under the BSD license (see accompanying file license.txt)

    Version 1.4.0
*/


#include "ordered_list/hdr_intrusive_lazy.h"
#include <cds/urcu/general_threaded.h>
#include <cds/intrusive/lazy_list_rcu.h>

namespace ordlist {
    namespace {
        typedef cds::urcu::gc< cds::urcu::general_threaded<> >    RCU ;
    }

    void IntrusiveLazyListHeaderTest::RCU_GPT_base_cmp()
    {
        typedef base_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::base_hook< co::gc<RCU> > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_base_less()
    {
        typedef base_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::base_hook< co::gc<RCU> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_base_cmpmix()
    {
        typedef base_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::base_hook< co::gc<RCU> > >
                ,co::less< less<item> >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_base_ic()
    {
        typedef base_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::base_hook< co::gc<RCU> > >
                ,co::less< less<item> >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_member_cmp()
    {
        typedef member_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_member_less()
    {
        typedef member_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_member_cmpmix()
    {
        typedef member_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::less< less<item> >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
    void IntrusiveLazyListHeaderTest::RCU_GPT_member_ic()
    {
        typedef member_int_item< RCU > item ;
        typedef ci::LazyList< RCU
            ,item
            ,ci::lazy_list::make_traits<
                ci::opt::hook< ci::lazy_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >    list    ;
        test_int<list>()    ;
    }
}   // namespace ordlist
