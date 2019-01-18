set(
        DTT_SOURCE
        member.cpp
)

set(
        DTT_IMPL_SOURCE
        impl/role.cpp
)

add_library(dtt SHARED ${DTT_SOURCE} ${DTT_IMPL_SOURCE})