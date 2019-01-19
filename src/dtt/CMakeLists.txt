set(
        DTT_SOURCE
        member.cpp
        role_manager.cpp
        member_manager.cpp)

set(
        DTT_IMPL_SOURCE
        impl/role.cpp
        )

add_library(dtt SHARED ${DTT_SOURCE} ${DTT_IMPL_SOURCE})