class User {
  final int? id;
  final String name;
  final String email;
  final String password;
  final DateTime dateCreated;

  User({
    this.id,
    required this.name,
    required this.email,
    required this.password,
    DateTime? dateCreated,
  }) : dateCreated = dateCreated ?? DateTime.now();

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'name': name,
      'email': email,
      'password': password,
      'dateCreated': dateCreated.toIso8601String(),
    };
  }

  factory User.fromMap(Map<String, dynamic> map) {
    return User(
      id: map['id'] as int?,
      name: map['name'] as String,
      email: map['email'] as String,
      password: map['password'] as String,
      dateCreated: DateTime.parse(map['dateCreated'] as String),
    );
  }
}
