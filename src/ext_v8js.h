#ifndef EXT_V8JS_H_
#define EXT_V8JS_H_

#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/vm/native-data.h"
#include <v8.h>
#include <libplatform/libplatform.h>

namespace HPHP
{
    class ArrayBufferAllocator : public v8::ArrayBuffer::Allocator {
        public:
            virtual void* Allocate(size_t length) {
                void* data = AllocateUninitialized(length);
                return data == NULL ? data : memset(data, 0, length);
            }
            virtual void* AllocateUninitialized(size_t length) { return malloc(length); }
            virtual void Free(void* data, size_t) { free(data); }
    };

    class v8jsExtension: public Extension
    {
        public:
            v8jsExtension(): Extension("v8js"){}
            virtual void moduleInit()
            {
                _initV8JsClass();
                loadSystemlib();            
            }
        private:
            void _initV8JsClass();
    };

    class V8Js {
        public:
            V8Js();
            ~V8Js();
            void validate() const;
            static Class *getClass();

            v8::Isolate *m_isolate;
            ArrayBufferAllocator *m_allocator;
            static Class *s_class;
            static const StaticString s_className;
    };
}
#endif
