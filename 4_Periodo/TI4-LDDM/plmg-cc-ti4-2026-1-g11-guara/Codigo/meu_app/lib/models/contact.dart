class Contact {
  final int? id;
  final int userId;
  final String name;
  final String relationship;
  final String phoneNumber;
  final DateTime dateCreated;

  Contact({
    this.id,
    required this.userId,
    required this.name,
    required this.relationship,
    required this.phoneNumber,
    DateTime? dateCreated,
  }) : dateCreated = dateCreated ?? DateTime.now();

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'userId': userId,
      'name': name,
      'relationship': relationship,
      'phoneNumber': phoneNumber,
      'dateCreated': dateCreated.toIso8601String(),
    };
  }

  factory Contact.fromMap(Map<String, dynamic> map) {
    return Contact(
      id: map['id'] as int?,
      userId: map['userId'] as int,
      name: map['name'] as String,
      relationship: map['relationship'] as String,
      phoneNumber: map['phoneNumber'] as String,
      dateCreated: DateTime.parse(map['dateCreated'] as String),
    );
  }
}
