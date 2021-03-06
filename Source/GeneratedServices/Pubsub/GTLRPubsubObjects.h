// NOTE: This file was generated by the ServiceGenerator.

// ----------------------------------------------------------------------------
// API:
//   Google Cloud Pub/Sub API (pubsub/v1)
// Description:
//   Provides reliable, many-to-many, asynchronous messaging between
//   applications.
// Documentation:
//   https://cloud.google.com/pubsub/docs

#if GTLR_BUILT_AS_FRAMEWORK
  #import "GTLR/GTLRObject.h"
#else
  #import "GTLRObject.h"
#endif

#if GTLR_RUNTIME_VERSION != 3000
#error This file was generated by a different version of ServiceGenerator which is incompatible with this GTLR library source.
#endif

@class GTLRPubsub_Binding;
@class GTLRPubsub_Message;
@class GTLRPubsub_Message_Attributes;
@class GTLRPubsub_Policy;
@class GTLRPubsub_PushConfig;
@class GTLRPubsub_PushConfig_Attributes;
@class GTLRPubsub_ReceivedMessage;
@class GTLRPubsub_Snapshot;
@class GTLRPubsub_Subscription;
@class GTLRPubsub_Topic;

// Generated comments include content from the discovery document; avoid them
// causing warnings since clang's checks are some what arbitrary.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Request for the Acknowledge method.
 */
@interface GTLRPubsub_AcknowledgeRequest : GTLRObject

/**
 *  The acknowledgment ID for the messages being acknowledged that was returned
 *  by the Pub/Sub system in the `Pull` response. Must not be empty.
 */
@property(nonatomic, strong, nullable) NSArray<NSString *> *ackIds;

@end


/**
 *  Associates `members` with a `role`.
 */
@interface GTLRPubsub_Binding : GTLRObject

/**
 *  Specifies the identities requesting access for a Cloud Platform resource.
 *  `members` can have the following values:
 *  * `allUsers`: A special identifier that represents anyone who is
 *  on the internet; with or without a Google account.
 *  * `allAuthenticatedUsers`: A special identifier that represents anyone
 *  who is authenticated with a Google account or a service account.
 *  * `user:{emailid}`: An email address that represents a specific Google
 *  account. For example, `alice\@gmail.com` or `joe\@example.com`.
 *  * `serviceAccount:{emailid}`: An email address that represents a service
 *  account. For example, `my-other-app\@appspot.gserviceaccount.com`.
 *  * `group:{emailid}`: An email address that represents a Google group.
 *  For example, `admins\@example.com`.
 *  * `domain:{domain}`: A Google Apps domain name that represents all the
 *  users of that domain. For example, `google.com` or `example.com`.
 */
@property(nonatomic, strong, nullable) NSArray<NSString *> *members;

/**
 *  Role that is assigned to `members`.
 *  For example, `roles/viewer`, `roles/editor`, or `roles/owner`.
 *  Required
 */
@property(nonatomic, copy, nullable) NSString *role;

@end


/**
 *  Request for the `CreateSnapshot` method.
 */
@interface GTLRPubsub_CreateSnapshotRequest : GTLRObject

/**
 *  The subscription whose backlog the snapshot retains.
 *  Specifically, the created snapshot is guaranteed to retain:
 *  (a) The existing backlog on the subscription. More precisely, this is
 *  defined as the messages in the subscription's backlog that are
 *  unacknowledged upon the successful completion of the
 *  `CreateSnapshot` request; as well as:
 *  (b) Any messages published to the subscription's topic following the
 *  successful completion of the CreateSnapshot request.
 *  Format is `projects/{project}/subscriptions/{sub}`.
 */
@property(nonatomic, copy, nullable) NSString *subscription;

@end


/**
 *  A generic empty message that you can re-use to avoid defining duplicated
 *  empty messages in your APIs. A typical example is to use it as the request
 *  or the response type of an API method. For instance:
 *  service Foo {
 *  rpc Bar(google.protobuf.Empty) returns (google.protobuf.Empty);
 *  }
 *  The JSON representation for `Empty` is empty JSON object `{}`.
 */
@interface GTLRPubsub_Empty : GTLRObject
@end


/**
 *  Response for the `ListSnapshots` method.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "snapshots" property. If returned as the result of a query, it
 *        should support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRPubsub_ListSnapshotsResponse : GTLRCollectionObject

/**
 *  If not empty, indicates that there may be more snapshot that match the
 *  request; this value should be passed in a new `ListSnapshotsRequest`.
 */
@property(nonatomic, copy, nullable) NSString *nextPageToken;

/**
 *  The resulting snapshots.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(nonatomic, strong, nullable) NSArray<GTLRPubsub_Snapshot *> *snapshots;

@end


/**
 *  Response for the `ListSubscriptions` method.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "subscriptions" property. If returned as the result of a query, it
 *        should support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRPubsub_ListSubscriptionsResponse : GTLRCollectionObject

/**
 *  If not empty, indicates that there may be more subscriptions that match
 *  the request; this value should be passed in a new
 *  `ListSubscriptionsRequest` to get more subscriptions.
 */
@property(nonatomic, copy, nullable) NSString *nextPageToken;

/**
 *  The subscriptions that match the request.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(nonatomic, strong, nullable) NSArray<GTLRPubsub_Subscription *> *subscriptions;

@end


/**
 *  Response for the `ListTopicSnapshots` method.
 */
@interface GTLRPubsub_ListTopicSnapshotsResponse : GTLRObject

/**
 *  If not empty, indicates that there may be more snapshots that match
 *  the request; this value should be passed in a new
 *  `ListTopicSnapshotsRequest` to get more snapshots.
 */
@property(nonatomic, copy, nullable) NSString *nextPageToken;

/** The names of the snapshots that match the request. */
@property(nonatomic, strong, nullable) NSArray<NSString *> *snapshots;

@end


/**
 *  Response for the `ListTopics` method.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "topics" property. If returned as the result of a query, it should
 *        support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRPubsub_ListTopicsResponse : GTLRCollectionObject

/**
 *  If not empty, indicates that there may be more topics that match the
 *  request; this value should be passed in a new `ListTopicsRequest`.
 */
@property(nonatomic, copy, nullable) NSString *nextPageToken;

/**
 *  The resulting topics.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(nonatomic, strong, nullable) NSArray<GTLRPubsub_Topic *> *topics;

@end


/**
 *  Response for the `ListTopicSubscriptions` method.
 */
@interface GTLRPubsub_ListTopicSubscriptionsResponse : GTLRObject

/**
 *  If not empty, indicates that there may be more subscriptions that match
 *  the request; this value should be passed in a new
 *  `ListTopicSubscriptionsRequest` to get more subscriptions.
 */
@property(nonatomic, copy, nullable) NSString *nextPageToken;

/** The names of the subscriptions that match the request. */
@property(nonatomic, strong, nullable) NSArray<NSString *> *subscriptions;

@end


/**
 *  A message data and its attributes. The message payload must not be empty;
 *  it must contain either a non-empty data field, or at least one attribute.
 */
@interface GTLRPubsub_Message : GTLRObject

/** Optional attributes for this message. */
@property(nonatomic, strong, nullable) GTLRPubsub_Message_Attributes *attributes;

/**
 *  The message payload.
 *
 *  Contains encoded binary data; GTLRBase64 can encode/decode (probably
 *  web-safe format).
 */
@property(nonatomic, copy, nullable) NSString *data;

/**
 *  ID of this message, assigned by the server when the message is published.
 *  Guaranteed to be unique within the topic. This value may be read by a
 *  subscriber that receives a `PubsubMessage` via a `Pull` call or a push
 *  delivery. It must not be populated by the publisher in a `Publish` call.
 */
@property(nonatomic, copy, nullable) NSString *messageId;

/**
 *  The time at which the message was published, populated by the server when
 *  it receives the `Publish` call. It must not be populated by the
 *  publisher in a `Publish` call.
 */
@property(nonatomic, strong, nullable) GTLRDateTime *publishTime;

@end


/**
 *  Optional attributes for this message.
 *
 *  @note This class is documented as having more properties of NSString. Use @c
 *        -additionalJSONKeys and @c -additionalPropertyForName: to get the list
 *        of properties and then fetch them; or @c -additionalProperties to
 *        fetch them all at once.
 */
@interface GTLRPubsub_Message_Attributes : GTLRObject
@end


/**
 *  Request for the ModifyAckDeadline method.
 */
@interface GTLRPubsub_ModifyAckDeadlineRequest : GTLRObject

/**
 *  The new ack deadline with respect to the time this request was sent to
 *  the Pub/Sub system. For example, if the value is 10, the new
 *  ack deadline will expire 10 seconds after the `ModifyAckDeadline` call
 *  was made. Specifying zero may immediately make the message available for
 *  another pull request.
 *  The minimum deadline you can specify is 0 seconds.
 *  The maximum deadline you can specify is 600 seconds (10 minutes).
 *
 *  Uses NSNumber of intValue.
 */
@property(nonatomic, strong, nullable) NSNumber *ackDeadlineSeconds;

/** List of acknowledgment IDs. */
@property(nonatomic, strong, nullable) NSArray<NSString *> *ackIds;

@end


/**
 *  Request for the ModifyPushConfig method.
 */
@interface GTLRPubsub_ModifyPushConfigRequest : GTLRObject

/**
 *  The push configuration for future deliveries.
 *  An empty `pushConfig` indicates that the Pub/Sub system should
 *  stop pushing messages from the given subscription and allow
 *  messages to be pulled and acknowledged - effectively pausing
 *  the subscription if `Pull` or `StreamingPull` is not called.
 */
@property(nonatomic, strong, nullable) GTLRPubsub_PushConfig *pushConfig;

@end


/**
 *  Defines an Identity and Access Management (IAM) policy. It is used to
 *  specify access control policies for Cloud Platform resources.
 *  A `Policy` consists of a list of `bindings`. A `Binding` binds a list of
 *  `members` to a `role`, where the members can be user accounts, Google
 *  groups,
 *  Google domains, and service accounts. A `role` is a named list of
 *  permissions
 *  defined by IAM.
 *  **Example**
 *  {
 *  "bindings": [
 *  {
 *  "role": "roles/owner",
 *  "members": [
 *  "user:mike\@example.com",
 *  "group:admins\@example.com",
 *  "domain:google.com",
 *  "serviceAccount:my-other-app\@appspot.gserviceaccount.com",
 *  ]
 *  },
 *  {
 *  "role": "roles/viewer",
 *  "members": ["user:sean\@example.com"]
 *  }
 *  ]
 *  }
 *  For a description of IAM and its features, see the
 *  [IAM developer's guide](https://cloud.google.com/iam/docs).
 */
@interface GTLRPubsub_Policy : GTLRObject

/**
 *  Associates a list of `members` to a `role`.
 *  `bindings` with no members will result in an error.
 */
@property(nonatomic, strong, nullable) NSArray<GTLRPubsub_Binding *> *bindings;

/**
 *  `etag` is used for optimistic concurrency control as a way to help
 *  prevent simultaneous updates of a policy from overwriting each other.
 *  It is strongly suggested that systems make use of the `etag` in the
 *  read-modify-write cycle to perform policy updates in order to avoid race
 *  conditions: An `etag` is returned in the response to `getIamPolicy`, and
 *  systems are expected to put that etag in the request to `setIamPolicy` to
 *  ensure that their change will be applied to the same version of the policy.
 *  If no `etag` is provided in the call to `setIamPolicy`, then the existing
 *  policy is overwritten blindly.
 *
 *  Contains encoded binary data; GTLRBase64 can encode/decode (probably
 *  web-safe format).
 */
@property(nonatomic, copy, nullable) NSString *ETag;

/**
 *  Deprecated.
 *
 *  Uses NSNumber of intValue.
 */
@property(nonatomic, strong, nullable) NSNumber *version;

@end


/**
 *  Request for the Publish method.
 */
@interface GTLRPubsub_PublishRequest : GTLRObject

/** The messages to publish. */
@property(nonatomic, strong, nullable) NSArray<GTLRPubsub_Message *> *messages;

@end


/**
 *  Response for the `Publish` method.
 */
@interface GTLRPubsub_PublishResponse : GTLRObject

/**
 *  The server-assigned ID of each published message, in the same order as
 *  the messages in the request. IDs are guaranteed to be unique within
 *  the topic.
 */
@property(nonatomic, strong, nullable) NSArray<NSString *> *messageIds;

@end


/**
 *  Request for the `Pull` method.
 */
@interface GTLRPubsub_PullRequest : GTLRObject

/**
 *  The maximum number of messages returned for this request. The Pub/Sub
 *  system may return fewer than the number specified.
 *
 *  Uses NSNumber of intValue.
 */
@property(nonatomic, strong, nullable) NSNumber *maxMessages;

/**
 *  If this field set to true, the system will respond immediately even if
 *  it there are no messages available to return in the `Pull` response.
 *  Otherwise, the system may wait (for a bounded amount of time) until at
 *  least one message is available, rather than returning no messages. The
 *  client may cancel the request if it does not wish to wait any longer for
 *  the response.
 *
 *  Uses NSNumber of boolValue.
 */
@property(nonatomic, strong, nullable) NSNumber *returnImmediately;

@end


/**
 *  Response for the `Pull` method.
 */
@interface GTLRPubsub_PullResponse : GTLRObject

/**
 *  Received Pub/Sub messages. The Pub/Sub system will return zero messages if
 *  there are no more available in the backlog. The Pub/Sub system may return
 *  fewer than the `maxMessages` requested even if there are more messages
 *  available in the backlog.
 */
@property(nonatomic, strong, nullable) NSArray<GTLRPubsub_ReceivedMessage *> *receivedMessages;

@end


/**
 *  Configuration for a push delivery endpoint.
 */
@interface GTLRPubsub_PushConfig : GTLRObject

/**
 *  Endpoint configuration attributes.
 *  Every endpoint has a set of API supported attributes that can be used to
 *  control different aspects of the message delivery.
 *  The currently supported attribute is `x-goog-version`, which you can
 *  use to change the format of the pushed message. This attribute
 *  indicates the version of the data expected by the endpoint. This
 *  controls the shape of the pushed message (i.e., its fields and metadata).
 *  The endpoint version is based on the version of the Pub/Sub API.
 *  If not present during the `CreateSubscription` call, it will default to
 *  the version of the API used to make such call. If not present during a
 *  `ModifyPushConfig` call, its value will not be changed. `GetSubscription`
 *  calls will always return a valid version, even if the subscription was
 *  created without this attribute.
 *  The possible values for this attribute are:
 *  * `v1beta1`: uses the push format defined in the v1beta1 Pub/Sub API.
 *  * `v1` or `v1beta2`: uses the push format defined in the v1 Pub/Sub API.
 */
@property(nonatomic, strong, nullable) GTLRPubsub_PushConfig_Attributes *attributes;

/**
 *  A URL locating the endpoint to which messages should be pushed.
 *  For example, a Webhook endpoint might use "https://example.com/push".
 */
@property(nonatomic, copy, nullable) NSString *pushEndpoint;

@end


/**
 *  Endpoint configuration attributes.
 *  Every endpoint has a set of API supported attributes that can be used to
 *  control different aspects of the message delivery.
 *  The currently supported attribute is `x-goog-version`, which you can
 *  use to change the format of the pushed message. This attribute
 *  indicates the version of the data expected by the endpoint. This
 *  controls the shape of the pushed message (i.e., its fields and metadata).
 *  The endpoint version is based on the version of the Pub/Sub API.
 *  If not present during the `CreateSubscription` call, it will default to
 *  the version of the API used to make such call. If not present during a
 *  `ModifyPushConfig` call, its value will not be changed. `GetSubscription`
 *  calls will always return a valid version, even if the subscription was
 *  created without this attribute.
 *  The possible values for this attribute are:
 *  * `v1beta1`: uses the push format defined in the v1beta1 Pub/Sub API.
 *  * `v1` or `v1beta2`: uses the push format defined in the v1 Pub/Sub API.
 *
 *  @note This class is documented as having more properties of NSString. Use @c
 *        -additionalJSONKeys and @c -additionalPropertyForName: to get the list
 *        of properties and then fetch them; or @c -additionalProperties to
 *        fetch them all at once.
 */
@interface GTLRPubsub_PushConfig_Attributes : GTLRObject
@end


/**
 *  A message and its corresponding acknowledgment ID.
 */
@interface GTLRPubsub_ReceivedMessage : GTLRObject

/** This ID can be used to acknowledge the received message. */
@property(nonatomic, copy, nullable) NSString *ackId;

/** The message. */
@property(nonatomic, strong, nullable) GTLRPubsub_Message *message;

@end


/**
 *  Request for the `Seek` method.
 */
@interface GTLRPubsub_SeekRequest : GTLRObject

/**
 *  The snapshot to seek to. The snapshot's topic must be the same as that of
 *  the provided subscription.
 *  Format is `projects/{project}/snapshots/{snap}`.
 */
@property(nonatomic, copy, nullable) NSString *snapshot;

/**
 *  The time to seek to.
 *  Messages retained in the subscription that were published before this
 *  time are marked as acknowledged, and messages retained in the
 *  subscription that were published after this time are marked as
 *  unacknowledged. Note that this operation affects only those messages
 *  retained in the subscription (configured by the combination of
 *  `message_retention_duration` and `retain_acked_messages`). For example,
 *  if `time` corresponds to a point before the message retention
 *  window (or to a point before the system's notion of the subscription
 *  creation time), only retained messages will be marked as unacknowledged,
 *  and already-expunged messages will not be restored.
 */
@property(nonatomic, strong, nullable) GTLRDateTime *time;

@end


/**
 *  GTLRPubsub_SeekResponse
 */
@interface GTLRPubsub_SeekResponse : GTLRObject
@end


/**
 *  Request message for `SetIamPolicy` method.
 */
@interface GTLRPubsub_SetIamPolicyRequest : GTLRObject

/**
 *  REQUIRED: The complete policy to be applied to the `resource`. The size of
 *  the policy is limited to a few 10s of KB. An empty policy is a
 *  valid policy but certain Cloud Platform services (such as Projects)
 *  might reject them.
 */
@property(nonatomic, strong, nullable) GTLRPubsub_Policy *policy;

@end


/**
 *  A snapshot resource.
 */
@interface GTLRPubsub_Snapshot : GTLRObject

/**
 *  The snapshot is guaranteed to exist up until this time.
 *  A newly-created snapshot expires no later than 7 days from the time of its
 *  creation. Its exact lifetime is determined at creation by the existing
 *  backlog in the source subscription. Specifically, the lifetime of the
 *  snapshot is `7 days - (age of oldest unacked message in the subscription)`.
 *  For example, consider a subscription whose oldest unacked message is 3 days
 *  old. If a snapshot is created from this subscription, the snapshot -- which
 *  will always capture this 3-day-old backlog as long as the snapshot
 *  exists -- will expire in 4 days. The service will refuse to create a
 *  snapshot that would expire in less than 1 hour after creation.
 */
@property(nonatomic, strong, nullable) GTLRDateTime *expireTime;

/** The name of the snapshot. */
@property(nonatomic, copy, nullable) NSString *name;

/** The name of the topic from which this snapshot is retaining messages. */
@property(nonatomic, copy, nullable) NSString *topic;

@end


/**
 *  A subscription resource.
 */
@interface GTLRPubsub_Subscription : GTLRObject

/**
 *  This value is the maximum time after a subscriber receives a message
 *  before the subscriber should acknowledge the message. After message
 *  delivery but before the ack deadline expires and before the message is
 *  acknowledged, it is an outstanding message and will not be delivered
 *  again during that time (on a best-effort basis).
 *  For pull subscriptions, this value is used as the initial value for the ack
 *  deadline. To override this value for a given message, call
 *  `ModifyAckDeadline` with the corresponding `ack_id` if using
 *  non-streaming pull or send the `ack_id` in a
 *  `StreamingModifyAckDeadlineRequest` if using streaming pull.
 *  The minimum custom deadline you can specify is 10 seconds.
 *  The maximum custom deadline you can specify is 600 seconds (10 minutes).
 *  If this parameter is 0, a default value of 10 seconds is used.
 *  For push delivery, this value is also used to set the request timeout for
 *  the call to the push endpoint.
 *  If the subscriber never acknowledges the message, the Pub/Sub
 *  system will eventually redeliver the message.
 *
 *  Uses NSNumber of intValue.
 */
@property(nonatomic, strong, nullable) NSNumber *ackDeadlineSeconds;

/**
 *  How long to retain unacknowledged messages in the subscription's backlog,
 *  from the moment a message is published.
 *  If `retain_acked_messages` is true, then this also configures the retention
 *  of acknowledged messages, and thus configures how far back in time a `Seek`
 *  can be done. Defaults to 7 days. Cannot be more than 7 days or less than 10
 *  minutes.
 */
@property(nonatomic, strong, nullable) GTLRDuration *messageRetentionDuration;

/**
 *  The name of the subscription. It must have the format
 *  `"projects/{project}/subscriptions/{subscription}"`. `{subscription}` must
 *  start with a letter, and contain only letters (`[A-Za-z]`), numbers
 *  (`[0-9]`), dashes (`-`), underscores (`_`), periods (`.`), tildes (`~`),
 *  plus (`+`) or percent signs (`%`). It must be between 3 and 255 characters
 *  in length, and it must not start with `"goog"`.
 */
@property(nonatomic, copy, nullable) NSString *name;

/**
 *  If push delivery is used with this subscription, this field is
 *  used to configure it. An empty `pushConfig` signifies that the subscriber
 *  will pull and ack messages using API methods.
 */
@property(nonatomic, strong, nullable) GTLRPubsub_PushConfig *pushConfig;

/**
 *  Indicates whether to retain acknowledged messages. If true, then
 *  messages are not expunged from the subscription's backlog, even if they are
 *  acknowledged, until they fall out of the `message_retention_duration`
 *  window.
 *
 *  Uses NSNumber of boolValue.
 */
@property(nonatomic, strong, nullable) NSNumber *retainAckedMessages;

/**
 *  The name of the topic from which this subscription is receiving messages.
 *  Format is `projects/{project}/topics/{topic}`.
 *  The value of this field will be `_deleted-topic_` if the topic has been
 *  deleted.
 */
@property(nonatomic, copy, nullable) NSString *topic;

@end


/**
 *  Request message for `TestIamPermissions` method.
 */
@interface GTLRPubsub_TestIamPermissionsRequest : GTLRObject

/**
 *  The set of permissions to check for the `resource`. Permissions with
 *  wildcards (such as '*' or 'storage.*') are not allowed. For more
 *  information see
 *  [IAM Overview](https://cloud.google.com/iam/docs/overview#permissions).
 */
@property(nonatomic, strong, nullable) NSArray<NSString *> *permissions;

@end


/**
 *  Response message for `TestIamPermissions` method.
 */
@interface GTLRPubsub_TestIamPermissionsResponse : GTLRObject

/**
 *  A subset of `TestPermissionsRequest.permissions` that the caller is
 *  allowed.
 */
@property(nonatomic, strong, nullable) NSArray<NSString *> *permissions;

@end


/**
 *  A topic resource.
 */
@interface GTLRPubsub_Topic : GTLRObject

/**
 *  The name of the topic. It must have the format
 *  `"projects/{project}/topics/{topic}"`. `{topic}` must start with a letter,
 *  and contain only letters (`[A-Za-z]`), numbers (`[0-9]`), dashes (`-`),
 *  underscores (`_`), periods (`.`), tildes (`~`), plus (`+`) or percent
 *  signs (`%`). It must be between 3 and 255 characters in length, and it
 *  must not start with `"goog"`.
 */
@property(nonatomic, copy, nullable) NSString *name;

@end


/**
 *  Request for the UpdateSnapshot method.
 */
@interface GTLRPubsub_UpdateSnapshotRequest : GTLRObject

/** The updated snpashot object. */
@property(nonatomic, strong, nullable) GTLRPubsub_Snapshot *snapshot;

/**
 *  Indicates which fields in the provided snapshot to update.
 *  Must be specified and non-empty.
 *
 *  String format is a comma-separated list of fields.
 */
@property(nonatomic, copy, nullable) NSString *updateMask;

@end


/**
 *  Request for the UpdateSubscription method.
 */
@interface GTLRPubsub_UpdateSubscriptionRequest : GTLRObject

/** The updated subscription object. */
@property(nonatomic, strong, nullable) GTLRPubsub_Subscription *subscription;

/**
 *  Indicates which fields in the provided subscription to update.
 *  Must be specified and non-empty.
 *
 *  String format is a comma-separated list of fields.
 */
@property(nonatomic, copy, nullable) NSString *updateMask;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
