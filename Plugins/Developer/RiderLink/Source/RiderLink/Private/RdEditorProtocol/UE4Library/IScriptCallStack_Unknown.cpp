//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.07.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "IScriptCallStack_Unknown.h"


namespace Jetbrains {
    namespace EditorPlugin {
        
        //companion
        
        //constants
        
        //initializer
        void IScriptCallStack_Unknown::initialize()
        {
        }
        
        //primary ctor
        IScriptCallStack_Unknown::IScriptCallStack_Unknown(rd::RdId unknownId_, rd::Buffer::ByteArray unknownBytes_) :
        IScriptCallStack(), rd::IUnknownInstance(std::move(unknownId_))
        
        {
            initialize();
        }
        
        //secondary constructor
        
        //default ctors and dtors
        IScriptCallStack_Unknown::IScriptCallStack_Unknown()
        {
            initialize();
        }
        
        //reader
        IScriptCallStack_Unknown IScriptCallStack_Unknown::read(rd::SerializationCtx& ctx, rd::Buffer & buffer)
        {
            throw std::logic_error("Unknown instances should not be read via serializer");
        }
        
        //writer
        void IScriptCallStack_Unknown::write(rd::SerializationCtx& ctx, rd::Buffer& buffer) const
        {
            buffer.write_byte_array_raw(unknownBytes_);
        }
        
        //virtual init
        
        //identify
        
        //getters
        
        //intern
        
        //equals trait
        bool IScriptCallStack_Unknown::equals(rd::ISerializable const& object) const
        {
            auto const &other = dynamic_cast<IScriptCallStack_Unknown const&>(object);
            if (this == &other) return true;
            
            return true;
        }
        
        //equality operators
        bool operator==(const IScriptCallStack_Unknown &lhs, const IScriptCallStack_Unknown &rhs) {
            if (lhs.type_name() != rhs.type_name()) return false;
            return lhs.equals(rhs);
        };
        bool operator!=(const IScriptCallStack_Unknown &lhs, const IScriptCallStack_Unknown &rhs){
            return !(lhs == rhs);
        }
        
        //hash code trait
        size_t IScriptCallStack_Unknown::hashCode() const noexcept
        {
            size_t __r = 0;
            return __r;
        }
        
        //type name trait
        std::string IScriptCallStack_Unknown::type_name() const
        {
            return "IScriptCallStack_Unknown";
        }
        
        //static type name trait
        std::string IScriptCallStack_Unknown::static_type_name()
        {
            return "IScriptCallStack_Unknown";
        }
        
        //polymorphic to string
        std::string IScriptCallStack_Unknown::toString() const
        {
            std::string res = "IScriptCallStack_Unknown\n";
            return res;
        }
        
        //external to string
        std::string to_string(const IScriptCallStack_Unknown & value)
        {
            return value.toString();
        }
    };
};
