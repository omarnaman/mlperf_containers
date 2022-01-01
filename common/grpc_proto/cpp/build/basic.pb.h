// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: basic.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_basic_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_basic_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_basic_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_basic_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_basic_2eproto;
class ItemResult;
struct ItemResultDefaultTypeInternal;
extern ItemResultDefaultTypeInternal _ItemResult_default_instance_;
class RequestItem;
struct RequestItemDefaultTypeInternal;
extern RequestItemDefaultTypeInternal _RequestItem_default_instance_;
class ThreadReply;
struct ThreadReplyDefaultTypeInternal;
extern ThreadReplyDefaultTypeInternal _ThreadReply_default_instance_;
class ThreadRequest;
struct ThreadRequestDefaultTypeInternal;
extern ThreadRequestDefaultTypeInternal _ThreadRequest_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::ItemResult* Arena::CreateMaybeMessage<::ItemResult>(Arena*);
template<> ::RequestItem* Arena::CreateMaybeMessage<::RequestItem>(Arena*);
template<> ::ThreadReply* Arena::CreateMaybeMessage<::ThreadReply>(Arena*);
template<> ::ThreadRequest* Arena::CreateMaybeMessage<::ThreadRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class RequestItem final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:RequestItem) */ {
 public:
  inline RequestItem() : RequestItem(nullptr) {}
  ~RequestItem() override;
  explicit constexpr RequestItem(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RequestItem(const RequestItem& from);
  RequestItem(RequestItem&& from) noexcept
    : RequestItem() {
    *this = ::std::move(from);
  }

  inline RequestItem& operator=(const RequestItem& from) {
    CopyFrom(from);
    return *this;
  }
  inline RequestItem& operator=(RequestItem&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RequestItem& default_instance() {
    return *internal_default_instance();
  }
  static inline const RequestItem* internal_default_instance() {
    return reinterpret_cast<const RequestItem*>(
               &_RequestItem_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RequestItem& a, RequestItem& b) {
    a.Swap(&b);
  }
  inline void Swap(RequestItem* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RequestItem* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RequestItem* New() const final {
    return new RequestItem();
  }

  RequestItem* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RequestItem>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RequestItem& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const RequestItem& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RequestItem* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "RequestItem";
  }
  protected:
  explicit RequestItem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kItemsFieldNumber = 1,
    kIdFieldNumber = 2,
  };
  // bytes items = 1;
  void clear_items();
  const std::string& items() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_items(ArgT0&& arg0, ArgT... args);
  std::string* mutable_items();
  PROTOBUF_MUST_USE_RESULT std::string* release_items();
  void set_allocated_items(std::string* items);
  private:
  const std::string& _internal_items() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_items(const std::string& value);
  std::string* _internal_mutable_items();
  public:

  // int32 id = 2;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:RequestItem)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr items_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_basic_2eproto;
};
// -------------------------------------------------------------------

class ItemResult final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ItemResult) */ {
 public:
  inline ItemResult() : ItemResult(nullptr) {}
  ~ItemResult() override;
  explicit constexpr ItemResult(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ItemResult(const ItemResult& from);
  ItemResult(ItemResult&& from) noexcept
    : ItemResult() {
    *this = ::std::move(from);
  }

  inline ItemResult& operator=(const ItemResult& from) {
    CopyFrom(from);
    return *this;
  }
  inline ItemResult& operator=(ItemResult&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ItemResult& default_instance() {
    return *internal_default_instance();
  }
  static inline const ItemResult* internal_default_instance() {
    return reinterpret_cast<const ItemResult*>(
               &_ItemResult_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ItemResult& a, ItemResult& b) {
    a.Swap(&b);
  }
  inline void Swap(ItemResult* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ItemResult* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ItemResult* New() const final {
    return new ItemResult();
  }

  ItemResult* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ItemResult>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ItemResult& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ItemResult& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ItemResult* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ItemResult";
  }
  protected:
  explicit ItemResult(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kResultsFieldNumber = 1,
    kIdFieldNumber = 2,
  };
  // bytes results = 1;
  void clear_results();
  const std::string& results() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_results(ArgT0&& arg0, ArgT... args);
  std::string* mutable_results();
  PROTOBUF_MUST_USE_RESULT std::string* release_results();
  void set_allocated_results(std::string* results);
  private:
  const std::string& _internal_results() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_results(const std::string& value);
  std::string* _internal_mutable_results();
  public:

  // int32 id = 2;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:ItemResult)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr results_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_basic_2eproto;
};
// -------------------------------------------------------------------

class ThreadRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ThreadRequest) */ {
 public:
  inline ThreadRequest() : ThreadRequest(nullptr) {}
  ~ThreadRequest() override;
  explicit constexpr ThreadRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ThreadRequest(const ThreadRequest& from);
  ThreadRequest(ThreadRequest&& from) noexcept
    : ThreadRequest() {
    *this = ::std::move(from);
  }

  inline ThreadRequest& operator=(const ThreadRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline ThreadRequest& operator=(ThreadRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ThreadRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const ThreadRequest* internal_default_instance() {
    return reinterpret_cast<const ThreadRequest*>(
               &_ThreadRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(ThreadRequest& a, ThreadRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(ThreadRequest* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ThreadRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ThreadRequest* New() const final {
    return new ThreadRequest();
  }

  ThreadRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ThreadRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ThreadRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ThreadRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ThreadRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ThreadRequest";
  }
  protected:
  explicit ThreadRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kThreadsFieldNumber = 1,
  };
  // int32 threads = 1;
  void clear_threads();
  ::PROTOBUF_NAMESPACE_ID::int32 threads() const;
  void set_threads(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_threads() const;
  void _internal_set_threads(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:ThreadRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 threads_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_basic_2eproto;
};
// -------------------------------------------------------------------

class ThreadReply final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ThreadReply) */ {
 public:
  inline ThreadReply() : ThreadReply(nullptr) {}
  ~ThreadReply() override;
  explicit constexpr ThreadReply(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ThreadReply(const ThreadReply& from);
  ThreadReply(ThreadReply&& from) noexcept
    : ThreadReply() {
    *this = ::std::move(from);
  }

  inline ThreadReply& operator=(const ThreadReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline ThreadReply& operator=(ThreadReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ThreadReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const ThreadReply* internal_default_instance() {
    return reinterpret_cast<const ThreadReply*>(
               &_ThreadReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(ThreadReply& a, ThreadReply& b) {
    a.Swap(&b);
  }
  inline void Swap(ThreadReply* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ThreadReply* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ThreadReply* New() const final {
    return new ThreadReply();
  }

  ThreadReply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ThreadReply>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ThreadReply& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ThreadReply& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ThreadReply* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ThreadReply";
  }
  protected:
  explicit ThreadReply(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kOkFieldNumber = 1,
  };
  // bool ok = 1;
  void clear_ok();
  bool ok() const;
  void set_ok(bool value);
  private:
  bool _internal_ok() const;
  void _internal_set_ok(bool value);
  public:

  // @@protoc_insertion_point(class_scope:ThreadReply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool ok_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_basic_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RequestItem

// bytes items = 1;
inline void RequestItem::clear_items() {
  items_.ClearToEmpty();
}
inline const std::string& RequestItem::items() const {
  // @@protoc_insertion_point(field_get:RequestItem.items)
  return _internal_items();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void RequestItem::set_items(ArgT0&& arg0, ArgT... args) {
 
 items_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:RequestItem.items)
}
inline std::string* RequestItem::mutable_items() {
  std::string* _s = _internal_mutable_items();
  // @@protoc_insertion_point(field_mutable:RequestItem.items)
  return _s;
}
inline const std::string& RequestItem::_internal_items() const {
  return items_.Get();
}
inline void RequestItem::_internal_set_items(const std::string& value) {
  
  items_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* RequestItem::_internal_mutable_items() {
  
  return items_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* RequestItem::release_items() {
  // @@protoc_insertion_point(field_release:RequestItem.items)
  return items_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void RequestItem::set_allocated_items(std::string* items) {
  if (items != nullptr) {
    
  } else {
    
  }
  items_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), items,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:RequestItem.items)
}

// int32 id = 2;
inline void RequestItem::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestItem::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestItem::id() const {
  // @@protoc_insertion_point(field_get:RequestItem.id)
  return _internal_id();
}
inline void RequestItem::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
}
inline void RequestItem::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:RequestItem.id)
}

// -------------------------------------------------------------------

// ItemResult

// bytes results = 1;
inline void ItemResult::clear_results() {
  results_.ClearToEmpty();
}
inline const std::string& ItemResult::results() const {
  // @@protoc_insertion_point(field_get:ItemResult.results)
  return _internal_results();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ItemResult::set_results(ArgT0&& arg0, ArgT... args) {
 
 results_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ItemResult.results)
}
inline std::string* ItemResult::mutable_results() {
  std::string* _s = _internal_mutable_results();
  // @@protoc_insertion_point(field_mutable:ItemResult.results)
  return _s;
}
inline const std::string& ItemResult::_internal_results() const {
  return results_.Get();
}
inline void ItemResult::_internal_set_results(const std::string& value) {
  
  results_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ItemResult::_internal_mutable_results() {
  
  return results_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ItemResult::release_results() {
  // @@protoc_insertion_point(field_release:ItemResult.results)
  return results_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ItemResult::set_allocated_results(std::string* results) {
  if (results != nullptr) {
    
  } else {
    
  }
  results_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), results,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:ItemResult.results)
}

// int32 id = 2;
inline void ItemResult::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ItemResult::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ItemResult::id() const {
  // @@protoc_insertion_point(field_get:ItemResult.id)
  return _internal_id();
}
inline void ItemResult::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
}
inline void ItemResult::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:ItemResult.id)
}

// -------------------------------------------------------------------

// ThreadRequest

// int32 threads = 1;
inline void ThreadRequest::clear_threads() {
  threads_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ThreadRequest::_internal_threads() const {
  return threads_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ThreadRequest::threads() const {
  // @@protoc_insertion_point(field_get:ThreadRequest.threads)
  return _internal_threads();
}
inline void ThreadRequest::_internal_set_threads(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  threads_ = value;
}
inline void ThreadRequest::set_threads(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_threads(value);
  // @@protoc_insertion_point(field_set:ThreadRequest.threads)
}

// -------------------------------------------------------------------

// ThreadReply

// bool ok = 1;
inline void ThreadReply::clear_ok() {
  ok_ = false;
}
inline bool ThreadReply::_internal_ok() const {
  return ok_;
}
inline bool ThreadReply::ok() const {
  // @@protoc_insertion_point(field_get:ThreadReply.ok)
  return _internal_ok();
}
inline void ThreadReply::_internal_set_ok(bool value) {
  
  ok_ = value;
}
inline void ThreadReply::set_ok(bool value) {
  _internal_set_ok(value);
  // @@protoc_insertion_point(field_set:ThreadReply.ok)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_basic_2eproto