//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.07.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef SCRIPTMSGCALLSTACK_H
#define SCRIPTMSGCALLSTACK_H


#include "protocol/Protocol.h"
#include "types/DateTime.h"
#include "impl/RdSignal.h"
#include "impl/RdProperty.h"
#include "impl/RdList.h"
#include "impl/RdSet.h"
#include "impl/RdMap.h"
#include "base/ISerializersOwner.h"
#include "base/IUnknownInstance.h"
#include "serialization/ISerializable.h"
#include "serialization/Polymorphic.h"
#include "serialization/NullableSerializer.h"
#include "serialization/ArraySerializer.h"
#include "serialization/InternedSerializer.h"
#include "serialization/SerializationCtx.h"
#include "serialization/Serializers.h"
#include "ext/RdExtBase.h"
#include "task/RdCall.h"
#include "task/RdEndpoint.h"
#include "task/RdSymmetricCall.h"
#include "std/to_string.h"
#include "std/hash.h"
#include "std/allocator.h"
#include "util/enum.h"
#include "util/gen_util.h"

#include <cstring>
#include <cstdint>
#include <vector>
#include <ctime>

#include "thirdparty.hpp"
#include "../instantiations.h"

#include "Runtime/Core/Public/Containers/UnrealString.h"
#include "../UE4Library/IScriptCallStack.h"
#include "IScriptMsg.h"

#include "UE4TypesMarshallers.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Containers/ContainerAllocationPolicies.h"

#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
/// <summary>
/// <p>Generated from: UE4Library.kt:159</p>
/// </summary>
namespace Jetbrains {
    namespace EditorPlugin {
        class ScriptMsgCallStack : public IScriptMsg
        {
            
            //companion
            
            //custom serializers
            private:
            
            //constants
            public:
            
            //fields
            protected:
            FString message_;
            rd::Wrapper<IScriptCallStack> scriptCallStack_;
            
            
            //initializer
            private:
            void initialize();
            
            //primary ctor
            public:
            ScriptMsgCallStack(FString message_, rd::Wrapper<IScriptCallStack> scriptCallStack_);
            
            //secondary constructor
            #ifdef __cpp_structured_bindings
                
                //deconstruct trait
            #endif
            
            //default ctors and dtors
            
            ScriptMsgCallStack() = delete;
            
            ScriptMsgCallStack(ScriptMsgCallStack const &) = default;
            
            ScriptMsgCallStack& operator=(ScriptMsgCallStack const &) = default;
            
            ScriptMsgCallStack(ScriptMsgCallStack &&) = default;
            
            ScriptMsgCallStack& operator=(ScriptMsgCallStack &&) = default;
            
            virtual ~ScriptMsgCallStack() = default;
            
            //reader
            static ScriptMsgCallStack read(rd::SerializationCtx& ctx, rd::Buffer & buffer);
            
            //writer
            void write(rd::SerializationCtx& ctx, rd::Buffer& buffer) const override;
            
            //virtual init
            
            //identify
            
            //getters
            FString const & get_message() const;
            IScriptCallStack const & get_scriptCallStack() const;
            
            //intern
            
            //equals trait
            private:
            bool equals(rd::ISerializable const& object) const override;
            
            //equality operators
            public:
            friend bool operator==(const ScriptMsgCallStack &lhs, const ScriptMsgCallStack &rhs);
            friend bool operator!=(const ScriptMsgCallStack &lhs, const ScriptMsgCallStack &rhs);
            
            //hash code trait
            size_t hashCode() const noexcept override;
            
            //type name trait
            std::string type_name() const override;
            
            //static type name trait
            static std::string static_type_name();
            
            //polymorphic to string
            private:
            std::string toString() const override;
            
            //external to string
            public:
            friend std::string to_string(const ScriptMsgCallStack & value);
        };
    };
};

#pragma warning( pop )


//hash code trait
namespace rd {
    template <> struct hash<Jetbrains::EditorPlugin::ScriptMsgCallStack> {
        size_t operator()(const Jetbrains::EditorPlugin::ScriptMsgCallStack & value) const noexcept {
            return value.hashCode();
        }
    };
}
#ifdef __cpp_structured_bindings
    
    //tuple trait
#endif


#endif // SCRIPTMSGCALLSTACK_H
